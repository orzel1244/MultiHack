#ifndef GLOW_H
#define GLOW_H

#include <QObject>
#include <class/Memory/memory.h>
#include <class/Offsets/offsets.h>
#include <QDebug>
#include <chrono>
#include <ctime>
#include <ratio>
#include <iostream>
#include <QThread>
#include <QtConcurrent>

class Color {
    float r;
    float g;
    float b;
    float a;
public:
    Color(float r_, float g_, float b_, float a_) {
        r=r_; g=g_; b=b_; a=a_;
    }
};

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
