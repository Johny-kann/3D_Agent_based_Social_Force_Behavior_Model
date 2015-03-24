#include "eperiment.h"

Eperiment::Eperiment(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    timer->start(500);
}

Eperiment::~Eperiment()
{

}

void Eperiment::timeout()
{
    qDebug()<<"time out";
}
