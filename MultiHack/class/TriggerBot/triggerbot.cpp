#include "triggerbot.h"

TriggerBot::TriggerBot(Offsets *off, Memory *mem) : QObject(off) {
    m_offsets = off;
    m_memory = mem;
}

void TriggerBot::shoot(){
    m_memory->write(m_memory->getModule("client.dll")+m_offsets->getAddress("dwForceAttack"), 6);
    Sleep(afterDelay);
}

void TriggerBot::setBindKey(int value){
    bindKey = value;
    qDebug() << bindKey;
}

// 5832996 - scout
// 33751331 - AWP
void TriggerBot::loop(){
    if(enabled && GetAsyncKeyState( bindKey )){
        DWORD player = m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwLocalPlayer"));
        DWORD playerWeapon = m_memory->read(player+m_offsets->getAddress("m_hActiveWeapon"));
        DWORD isPlayerScoping = m_memory->read(player+m_offsets->getAddress("m_bIsScoped"));
        if(((playerWeapon == 5832996 || playerWeapon == 33751331) && isPlayerScoping) || (playerWeapon != 5832996 && playerWeapon != 33751331)){
            DWORD playerTeam = m_memory->read(player+m_offsets->getAddress("m_iTeamNum"));
            DWORD crosshair = m_memory->read(player+m_offsets->getAddress("m_iCrosshairId"));
            if(crosshair > 0 && crosshair < 40){
                DWORD ent = m_memory->read(m_memory->getModule("client.dll")+m_offsets->getAddress("dwEntityList")+(crosshair-1)*0x10);
                DWORD entTeam = m_memory->read(ent+m_offsets->getAddress("m_iTeamNum"));
                qDebug() << crosshair << entTeam << playerTeam;
                if(entTeam != playerTeam){
                    //                trigger
                    qDebug() << "shoot";
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
