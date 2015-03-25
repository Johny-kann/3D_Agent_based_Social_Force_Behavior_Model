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

class test
{
public:
    int *aa;

    test()
    {
        int bb[] = {1,2,3};
        this->aa = new int[3];

        for(int i=0;i<3;i++)
        {
            aa[i]=bb[i];
        }

    //    qDebug()<<aa[0]<<aa[1]<<aa[2];
    }

};
