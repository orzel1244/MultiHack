#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <class/Offsets/offsets.h>

int main(int argc, char *argv[]){

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    Offsets ofssets;
    qDebug() << ofssets.getAddress("dwLocalPlayer"); // TODO: Zrobic że jeżeli nie ma pliku, to żeby
                                                     // czekało na SLOT(gotHttp()) a potem rekurencyjnie
                                                     // wykonało samo siebie



    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
