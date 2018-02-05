#include "manager.h"

Manager::Manager(QQmlContext *ctx){
    m_memory = new Memory;
    m_ctx = ctx;
    m_offsets = new Offsets;
    connect(m_offsets, SIGNAL(ready()), this, SLOT(start()));
}


void Manager::start(){
    qDebug() << "Manager is ready to start";
    m_triggerBot = new TriggerBot(m_offsets, m_memory);
    QTimer *triggerBotTimer = new QTimer;
    connect(triggerBotTimer, SIGNAL(timeout()), m_triggerBot, SLOT(loop()));
    triggerBotTimer->setInterval(0);
    triggerBotTimer->start(0);
    m_ctx->setContextProperty("triggerbot", m_triggerBot);
//    m_ctx->setContextProperty("triggerbot", &m_triggerBot);
}
