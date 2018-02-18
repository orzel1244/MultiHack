#include "antiscriptkiddie.h"

AntiScriptKiddie::AntiScriptKiddie(QObject *parent) : QObject(parent){
}

bool AntiScriptKiddie::isAuthorized(){
    return authorized;
}

bool AntiScriptKiddie::auth(QString password){
    QString h = QCryptographicHash::hash(QByteArray::fromStdString(password.toStdString()),QCryptographicHash::Sha224);
    if (h == m_password){
        authorized = true;
        return true;
    }
    authorized = false;
    return false;
}
