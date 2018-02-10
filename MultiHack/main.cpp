#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <class/Offsets/offsets.h>
#include <class/Manager/manager.h>
#include <class/KeyTranslator/keytranslator.h>
#include <QQmlContext>

int main(int argc, char *argv[]){

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();
    Manager mgr(ctx);
    ctx->setContextProperty("manager", &mgr);
    KeyTranslator ktr;
    ctx->setContextProperty("keyTranslator", &ktr);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
