#ifndef KEYTRANSLATOR_H
#define KEYTRANSLATOR_H

#include <QObject>
#include <ctype.h>
#include <QMap>
#include <QDebug>

class KeyTranslator : public QObject
{
    Q_OBJECT
public:
    explicit KeyTranslator(QObject *parent = nullptr);
    int getCode(QString key);
    QMap<QString, int> keyCodes;
private:
    void add(QString v0, int v1);

};

#endif // KEYTRANSLATOR_H
