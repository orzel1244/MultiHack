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
        // perf
//        auto t1 = std::chrono::high_resolution_clock::now();

        DWORD glowManager = m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwGlowObjectManager"));
        DWORD player = m_memory->read(m_memory->getModule("client.dll")+
                                      m_offsets->getAddress("dwLocalPlayer"));
        DWORD playerTeam = m_memory->read(player+m_offsets->getAddress("m_iTeamNum"));
        for(int i=1; i<=32; i++){
            DWORD theEnt = m_memory->read(m_memory->getModule("client.dll")+
                                          m_offsets->getAddress("dwEntityList")+
                                          (i-1)*0x10);
            DWORD glowIndex = m_memory->read(theEnt+m_offsets->getAddress("m_iGlowIndex"));
            DWORD entTeam = m_memory->read(theEnt+m_offsets->getAddress("m_iTeamNum"));
            DWORD classID = m_memory->read(theEnt+0x14);


            if(classID == 0){ // classId = player
                if(entTeam != playerTeam ){
                    m_memory->write(glowManager+(glowIndex * 0x38)+0x4, Color(1.f,0,0,0.7f)); // rgba
                    m_memory->write(glowManager+(glowIndex * 0x38)+0x24, 1);
                }
            }
        }
//        auto t2 = std::chrono::high_resolution_clock::now();
//        auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
//        std::chrono::duration<long, std::micro> int_usec = int_ms;
//        std::cout << int_usec.count() << std::endl;
    }
}
