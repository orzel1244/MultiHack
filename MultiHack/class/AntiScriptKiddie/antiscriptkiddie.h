#ifndef ANTISCRIPTKIDDIE_H
#define ANTISCRIPTKIDDIE_H

#include <QObject>
#include <QDebug>
#include <QCryptographicHash>

class AntiScriptKiddie : public QObject {
    Q_OBJECT
public:
    explicit AntiScriptKiddie(QObject *parent = nullptr);
private:
    QString m_password = "\x94\xA3?\x99\x89\xEB]\x96""c\xCE\xCB}}*\xAA\xC8\xA1\xC5\xE1[\xAA\xDE\x8F\xB2\x84\x02""d\xF8";
protected:
    bool authorized=false;
public slots:
    bool isAuthorized();
    bool auth(QString password);
};

#endif // ANTISCRIPTKIDDIE_H
