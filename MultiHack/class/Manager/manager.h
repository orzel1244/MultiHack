#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <class/Offsets/offsets.h>
#include <class/TriggerBot/triggerbot.h>
#include <class/Memory/memory.h>
#include <QQmlContext>
#include <QDebug>
#include <QTimer>

class Manager : public QObject{
    Q_OBJECT
public:
    explicit Manager(QQmlContext* ctx);

signals:

private:
    Offsets* m_offsets;
    TriggerBot* m_triggerBot;
    Memory* m_memory;

    QQmlContext* m_ctx;
public slots:
    void start();


};

#endif // MANAGER_H
