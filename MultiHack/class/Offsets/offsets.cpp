#include "offsets.h"

Offsets::Offsets(){
    manager = new QNetworkAccessManager(this);
    update();
}

void Offsets::update(){
    QNetworkRequest request(QUrl("https://raw.githubusercontent.com/frk1/hazedumper/master/csgo.min.json"));
    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    conf.setProtocol (QSsl::AnyProtocol);
    request.setSslConfiguration(conf);

    reply = manager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(gotHttp()));
}

int Offsets::getAddress(QString name){
    QJsonDocument doc;
    QFile file("offsets.min.json");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString v(file.readAll());
        QJsonDocument doc = QJsonDocument::fromJson(v.toUtf8());
        bool error=false;
        if (!doc.isNull()) {
            if (!doc.isObject()) {
                qDebug() << "Document is not an object" << endl;
                error=true;
            }
        } else {
            qDebug() << "Invalid JSON...\n" << v << endl;
            error=true;
        }
        if (!error){
            QJsonObject obj(doc.object());
            QJsonObject signatures=obj.value("signatures").toObject();
            if(!signatures.value(name).isUndefined()){
                return signatures.value(name).toInt();
            } else {
                QJsonObject netvars=obj.value("netvars").toObject();
                if(!netvars.value(name).isUndefined()){
                    return netvars.value(name).toInt();
                }
            }
        }
        file.close();
    } else {
        // ..?
        // TODO: Tu czekać na gotHttp() a potem rekurencyjnie odpalić tą samą funkcje
        //connect(reply, SIGNAL(finished()),    ));

    }
    return 404;
}

void Offsets::gotHttp() {
    QFile file("offsets.min.json");
    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);
        stream << reply->readAll();
        file.close();
    }
    emit ready();
}
