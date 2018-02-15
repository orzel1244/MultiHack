#include "triggerbot.h"

TriggerBot::TriggerBot(Offsets *off, Memory *mem) : QObject(off) {
    m_offsets = off;
    m_memory = mem;
}

void TriggerBot::shoot(){
    m_memory->write(m_memory->getModule("client.dll")+m_offsets->getAddress("dwForceAttack"), 6);
    Sleep(afterDelay);
}

bool TriggerBot::isSniper(int w){
    if(w == scoutId || w == awpId || w == autoCT || w == autoT){
        return true;
    }
    if(w != scoutId && w != awpId && w != autoCT && w != autoT){
        return false;
    }
    return false;
}

void TriggerBot::setBindEnabled(bool value){
    bindEnabled = value;
}

void TriggerBot::setBindKey(int value){
    bindKey = value;
}
void TriggerBot::loop(){
    if(enabled && (GetAsyncKeyState( bindKey ) || bindEnabled == false)){
        DWORD player = m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwLocalPlayer"));
        DWORD playerWeapon = m_memory->read(player+m_offsets->getAddress("m_hActiveWeapon"));

        DWORD weaponEnt = m_memory->read(m_memory->getModule("client.dll")+
                                         m_offsets->getAddress("dwEntityList") + ((playerWeapon & 0xFFF)-1)*0x10);
        int weaponID = m_memory->read(weaponEnt+m_offsets->getAddress("m_iItemDefinitionIndex"));
        DWORD isPlayerScoping = m_memory->read(player+m_offsets->getAddress("m_bIsScoped"));
        if(((isSniper(weaponID)&&isPlayerScoping)||(!isSniper(weaponID)))){
            DWORD playerTeam = m_memory->read(player+m_offsets->getAddress("m_iTeamNum"));
            DWORD crosshair = m_memory->read(player+m_offsets->getAddress("m_iCrosshairId"));
            if(crosshair > 0 && crosshair < 40){
                DWORD ent = m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwEntityList")+(crosshair-1)*0x10);
                DWORD entTeam = m_memory->read(ent+m_offsets->getAddress("m_iTeamNum"));
                if(entTeam != playerTeam){
                    Sleep(beforeDelay);
                    shoot();
                }
            }
        }
    }
}

void TriggerBot::setEnabled(bool value){
    enabled = value;
    if(enabled){
        m_memory->attachProcess();
    }
}

bool TriggerBot::isEnabled(){
    return enabled;
}

void TriggerBot::setAfterDelay(int value){
    afterDelay = value;
}

void TriggerBot::setBeforeDelay(int value){
    beforeDelay = value;
}
