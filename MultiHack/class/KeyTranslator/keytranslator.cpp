#include "keytranslator.h"

KeyTranslator::KeyTranslator(QObject *parent) : QObject(parent){
    add("A", 0x41);
    add("B", 0x42);
    add("C", 0x43);
}



int KeyTranslator::getCode(QString key){
    QMapIterator<QString, int> i(keyCodes);
    while (i.hasNext()) {
        i.next();
        if(key == i.key()){
            return i.value();
        }
    }
    return 404;
}

void KeyTranslator::add(QString v0, int v1){
    keyCodes.insert(v0,v1);
}

