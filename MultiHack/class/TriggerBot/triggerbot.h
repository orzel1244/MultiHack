#ifndef TRIGGERBOT_H
#define TRIGGERBOT_H

#include <QObject>
#include <class/Offsets/offsets.h>
#include <QDebug>

class TriggerBot : public QObject{
    Q_OBJECT
public:
    explicit TriggerBot(Offsets *off);

private:
    Offsets* m_offsets;
    bool enabled=false;
private slots:
    void loop();
public slots:
    void setEnabled(bool value);
    bool isEnabled();
};

#endif // TRIGGERBOT_H
