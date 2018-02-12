#ifndef BUNNYHOP_H
#define BUNNYHOP_H

#include <QObject>
#include <class/Memory/memory.h>
#include <class/Offsets/offsets.h>
#include <QDebug>

class BunnyHop : public QObject
{
    Q_OBJECT
public:
    explicit BunnyHop(Offsets *off, Memory *mem);

private:
    Offsets* m_offsets;
    Memory* m_memory;
    bool enabled=false;
    int bindKey=0x20; // space
public slots:
    void setEnabled(bool value);
    void setBindKey(int value);
    bool isEnabled();
    void loop();
};

#endif // BUNNYHOP_H
