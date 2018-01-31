#ifndef OFFSETSUPDATER_H
#define OFFSETSUPDATER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

class OffsetsUpdater : public QObject {
    Q_OBJECT
public:
    explicit OffsetsUpdater(QObject *parent = nullptr);

signals:

public slots:
    void gotHttp();

private:
    QNetworkReply *reply;
    QNetworkAccessManager *manager;
};

#endif // OFFSETSUPDATER_H
