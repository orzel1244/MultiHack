#include "misc.h"

Misc::Misc(Offsets *off, Memory *mem) : QObject(off){
    m_memory = mem;
    m_offsets = off;
}


void Misc::loop(){
    if(noFlash){
        m_memory->write(m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwLocalPlayer"))+m_offsets->getAddress("m_flFlashDuration"), 0);
    }
    if(radar){
        DWORD player = m_memory->read(m_memory->getModule("client.dll")+
                                      m_offsets->getAddress("dwLocalPlayer"));
        DWORD playerTeam = m_memory->read(player+m_offsets->getAddress("m_iTeamNum"));
        for(int i=0; i<=32; i++){
            DWORD theEnt = m_memory->read(m_memory->getModule("client.dll")+
                                          m_offsets->getAddress("dwEntityList")+
                                          (i-1)*0x10);
            DWORD entTeam = m_memory->read(theEnt+m_offsets->getAddress("m_iTeamNum"));
            if(entTeam != playerTeam ){
                if(m_memory->read(theEnt+0x14) == 0){ // classId = player
                    m_memory->write(theEnt+m_offsets->getAddress("m_bSpotted"), 1);
                }
            }
        }
    }
}

void Misc::setNoFlash(bool value){
    noFlash = value;
}

void Misc::setRadar(bool value){
    radar = value;
}

