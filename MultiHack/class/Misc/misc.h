#ifndef MISC_H
#define MISC_H

#include <QObject>
#include <class/Memory/memory.h>
#include <class/Offsets/offsets.h>
#include <QDebug>


class Misc : public QObject{
    Q_OBJECT
public:
    explicit Misc(Offsets *off, Memory *mem);

public slots:
    void loop();
    void setNoFlash(bool value);
    void setRadar(bool value);
    void setSilentNoFlash(bool value);
private:
    bool radar=false;
    bool noFlash=false;
    bool silentNoFlash=false;
    Offsets* m_offsets;
    Memory* m_memory;

public slots:
};

#endif // MISC_H
