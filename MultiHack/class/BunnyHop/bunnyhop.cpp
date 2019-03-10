#include "bunnyhop.h"

BunnyHop::BunnyHop(Offsets *off, Memory *mem){
    m_offsets = off;
    m_memory = mem;
}

void BunnyHop::setBindKey(int value)
{
    bindKey = value;
}

void BunnyHop::setEnabled(bool value){
    enabled = value;
}

bool BunnyHop::isEnabled(){
    return enabled;
}

void BunnyHop::loop(){
    if(enabled && GetAsyncKeyState( bindKey )){
        DWORD player = m_memory->read(m_memory->getModule("client_panorama.dll")+m_offsets->getAddress("dwLocalPlayer"));
        DWORD flag = m_memory->read(player+m_offsets->getAddress("m_fFlags"));
        if(flag == 257){
            m_memory->write(m_memory->getModule("client_panorama.dll")+m_offsets->getAddress("dwForceJump"), 6);
        }
    }
}
