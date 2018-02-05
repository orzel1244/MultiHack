#include "triggerbot.h"

TriggerBot::TriggerBot(Offsets *off) : QObject(off) {
    m_offsets = off;
}

void TriggerBot::loop(){
    qDebug() << enabled;
    if(enabled){

    }
}

void TriggerBot::setEnabled(bool value){
    enabled = value;
}

bool TriggerBot::isEnabled(){
    return enabled;
}
