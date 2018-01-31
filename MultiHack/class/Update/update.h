#ifndef UPDATE_H
#define UPDATE_H

#include <QObject>

class Update : public QObject
{
    Q_OBJECT
public:
    explicit Update(QObject *parent = nullptr);

signals:

public slots:
};

#endif // UPDATE_H