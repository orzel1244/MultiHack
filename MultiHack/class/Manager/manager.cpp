#include "manager.h"

Manager::Manager(QQmlContext *ctx){
    m_memory = new Memory;
    m_offsets = new Offsets;
    m_ctx = ctx;
    connect(m_offsets, SIGNAL(ready()), this, SLOT(start()));
}


void Manager::start(){
    qDebug() << "Manager is ready to start";
    m_triggerBot = new TriggerBot(m_offsets, m_memory);
    m_bhop = new BunnyHop(m_offsets, m_memory);
    m_misc = new Misc(m_offsets, m_memory);

    QTimer *triggerBotTimer = new QTimer;
    connect(triggerBotTimer, SIGNAL(timeout()), m_triggerBot, SLOT(loop()));
    triggerBotTimer->setInterval(0);
    triggerBotTimer->start(0);

    QTimer *bhopTimer = new QTimer;
    connect(bhopTimer, SIGNAL(timeout()), m_bhop, SLOT(loop()));
    bhopTimer->setInterval(0);
    bhopTimer->start(0);

    QTimer *miscTimer = new QTimer;
    connect(miscTimer, SIGNAL(timeout()), m_misc, SLOT(loop()));
    miscTimer->setInterval(0);
    miscTimer->start(0);

    m_ctx->setContextProperty("triggerbot", m_triggerBot);
    m_ctx->setContextProperty("bunnyhop", m_bhop);
    m_ctx->setContextProperty("misc", m_misc);
}
