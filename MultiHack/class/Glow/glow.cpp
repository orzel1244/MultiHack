#include "glow.h"

Glow::Glow(Offsets *off, Memory *mem) : QObject(off){
    m_memory = mem;
    m_offsets = off;
}

void Glow::setEnabled(bool value){
    enabled = value;
}

bool Glow::isEnabled(){
    return enabled;
}

void Glow::loop(){
    if(enabled){
        DWORD glowManager = m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwGlowObjectManager"));
        DWORD player = m_memory->read(m_memory->getModule("client.dll")+
                                      m_offsets->getAddress("dwLocalPlayer"));
        DWORD playerTeam = m_memory->read(player+m_offsets->getAddress("m_iTeamNum"));
        for(int i=0; i<=32; i++){
            DWORD theEnt = m_memory->read(m_memory->getModule("client.dll")+
                                          m_offsets->getAddress("dwEntityList")+
                                          (i-1)*0x10);
            DWORD glowIndex = m_memory->read(theEnt+m_offsets->getAddress("m_iGlowIndex"));
            DWORD entTeam = m_memory->read(theEnt+m_offsets->getAddress("m_iTeamNum"));
            DWORD classID = m_memory->read(theEnt+0x14);
            if(classID == 0){ // classId = player
                if(entTeam != playerTeam ){
                    m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0x4, 1.f); // r
                    m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0xB, 0.0f); // g
                    m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0xC, 0.0f); // b
                    m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0x10, 1.f);
                    m_memory->write(glowManager+(glowIndex * 0x38)+0x24, 1);
                    m_memory->write(glowManager+(glowIndex * 0x38)+0x25, 0);
                }
            }
            if(classID == 2760 || classID == 1356){
                m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0x4, 1.f); // r
                m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0xB, 0.0f); // g
                m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0xC, 0.0f); // b
                m_memory->writeFloat(glowManager+(glowIndex * 0x38)+0x10, 1.f);
                m_memory->write(glowManager+(glowIndex * 0x38)+0x24, 1);
                m_memory->write(glowManager+(glowIndex * 0x38)+0x25, 0);
            }
        }
    }
}
