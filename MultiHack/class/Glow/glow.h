#ifndef GLOW_H
#define GLOW_H

#include <QObject>
#include <class/Memory/memory.h>
#include <class/Offsets/offsets.h>
#include <QDebug>

class Glow : public QObject {
    Q_OBJECT
public:
    explicit Glow(Offsets *off, Memory *mem);
private:
    Offsets* m_offsets;
    Memory* m_memory;
    bool enabled=false;

public slots:
    void setEnabled(bool value);
    bool isEnabled();
    void loop();
};

#endif // GLOW_H
