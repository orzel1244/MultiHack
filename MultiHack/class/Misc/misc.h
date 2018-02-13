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
private:
    bool noFlash=false;
    Offsets* m_offsets;
    Memory* m_memory;

public slots:
};

#endif // MISC_H
