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
    int beforeDelay=15;
    int afterDelay=35;

private:
    Offsets* m_offsets;
    Memory* m_memory;
    bool enabled=false;
    void shoot();
    int bindKey=0x12;
    bool bindEnabled=true;
    bool isSniper(int w);
    //weps
    int scoutId = 40;
    int awpId = 9;
    int autoT = 11;
    int autoCT = 38;
private slots:
    void loop();
public slots:
    void setBindKey(int value);
    void setBindEnabled(bool value);
    void setEnabled(bool value);
    bool isEnabled();
    void setBeforeDelay(int value);
    void setAfterDelay(int value);
};

#endif // TRIGGERBOT_H
