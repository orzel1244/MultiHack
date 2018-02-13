#include "misc.h"

Misc::Misc(Offsets *off, Memory *mem) : QObject(off){
    m_memory = mem;
    m_offsets = off;
}


void Misc::loop(){
    if(noFlash){
        m_memory->write(m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwLocalPlayer"))+m_offsets->getAddress("m_flFlashDuration"), 0);
    }
}

void Misc::setNoFlash(bool value){
    noFlash = value;
}

