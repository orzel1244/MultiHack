#include "keytranslator.h"

KeyTranslator::KeyTranslator(QObject *parent) : QObject(parent){
    add("SPACE", 0x20);
    add("A", 0x41);
    add("B", 0x42);
    add("C", 0x43);
    add("D", 0x44);
    add("E", 0x45);
    add("F", 0x46);
    add("G", 0x47);
    add("H", 0x48);
    add("I", 0x49);
    add("J", 0x4A);
    add("K", 0x4B);
    add("L", 0x4C);
    add("M", 0x4D);
    add("N", 0x4E);
    add("O", 0x4F);
    add("P", 0x50);
    add("Q", 0x51);
    add("R", 0x52);
    add("S", 0x53);
    add("T", 0x54);
    add("U", 0x55);
    add("V", 0x56);
    add("W", 0x57);
    add("X", 0x58);
    add("Y", 0x59);
    add("Z", 0x5A);
    add("ALT", 0x12);
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

