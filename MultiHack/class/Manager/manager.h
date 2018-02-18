#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <class/Offsets/offsets.h>
#include <class/TriggerBot/triggerbot.h>
#include <class/Memory/memory.h>
#include <class/BunnyHop/bunnyhop.h>
#include <class/Glow/glow.h>
#include <class/Misc/misc.h>
#include <QQmlContext>
#include <QDebug>
#include <QTimer>
#include <QtConcurrent>

class Manager : public QObject{
    Q_OBJECT
public:
    explicit Manager(QQmlContext* ctx);

signals:

private:
    Offsets* m_offsets;
    TriggerBot* m_triggerBot;
    BunnyHop* m_bhop;
    Memory* m_memory;
    Misc* m_misc;
    Glow* m_glow;

    QQmlContext* m_ctx;
public slots:
    void start();

};

#endif // MANAGER_H
