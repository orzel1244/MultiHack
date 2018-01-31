#include "offsetsupdater.h"

OffsetsUpdater::OffsetsUpdater(QObject *parent) : QObject(parent){
    qDebug() << "start";
    manager = new QNetworkAccessManager(this);
//    connect(manager, SIGNAL(finished(reply)),
//            this, SLOT(gotHttp()));
    QNetworkRequest request(QUrl("http://github.com/frk1/hazedumper/blob/master/csgo.min.json"));
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(gotHttp()));
}

void OffsetsUpdater::gotHttp() {
    qDebug() << "recided";
    qDebug() << reply->readAll();
}
