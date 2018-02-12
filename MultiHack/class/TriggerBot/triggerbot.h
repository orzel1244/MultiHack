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
    int beforeDelay=100;
    int afterDelay=100;

private:
    Offsets* m_offsets;
    Memory* m_memory;
    bool enabled=false;
    void shoot();
    int bindKey=0x12;
private slots:
    void loop();
public slots:
    void setBindKey(int value);
    void setEnabled(bool value);
    bool isEnabled();
    void setBeforeDelay(int value);
    void setAfterDelay(int value);
};

#endif // TRIGGERBOT_H
