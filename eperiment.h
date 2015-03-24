#ifndef EPERIMENT_H
#define EPERIMENT_H

#include <QObject>
#include <QTimer>
#include<QDebug>

class Eperiment : public QObject
{
    Q_OBJECT
public:
    explicit Eperiment(QObject *parent = 0);
    ~Eperiment();

    QTimer *timer;

signals:

public slots:
    void timeout();
};

#endif // EPERIMENT_H
