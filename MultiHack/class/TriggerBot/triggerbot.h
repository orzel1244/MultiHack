#ifndef TRIGGERBOT_H
#define TRIGGERBOT_H

#include <QObject>
#include <class/Offsets/offsets.h>
#include <class/Memory/memory.h>
#include <QDebug>

class TriggerBot : public QObject{
    Q_OBJECT
public:
    explicit TriggerBot(Offsets *off, Memory *mem);

    void setDelay(int value);

private:
    Offsets* m_offsets;
    Memory* m_memory;
    bool enabled=false;
    void shoot();
    int delay=20;
private slots:
    void loop();
public slots:
    void setEnabled(bool value);
    bool isEnabled();
};

#endif // TRIGGERBOT_H
