#ifndef OFFSETS_H
#define OFFSETS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class Offsets : public QObject {
    Q_OBJECT
public:
    Offsets();
    void update();

signals:
    void ready();
public slots:
    int getAddress(QString name);
    void gotHttp();

private:
    QNetworkReply *reply;
    QNetworkAccessManager *manager;
};

#endif // OFFSETS_H
