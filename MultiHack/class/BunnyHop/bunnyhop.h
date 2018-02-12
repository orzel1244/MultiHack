#ifndef BUNNYHOP_H
#define BUNNYHOP_H

#include <QObject>

class BunnyHop : public QObject
{
    Q_OBJECT
public:
    explicit BunnyHop(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BUNNYHOP_H