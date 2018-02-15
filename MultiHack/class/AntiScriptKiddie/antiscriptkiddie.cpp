#include "antiscriptkiddie.h"

AntiScriptKiddie::AntiScriptKiddie(QObject *parent) : QObject(parent){
}

bool AntiScriptKiddie::pass(QString password){
    QString h = QCryptographicHash::hash(QByteArray::fromStdString(password.toStdString()),QCryptographicHash::Sha224);
    if (h == m_password){
        return true;
    }
    return false;
}
