#include "dummy.h"
#include "ui_dummy.h"

Dummy::Dummy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dummy)
{
    ui->setupUi(this);
}

Dummy::~Dummy()
{
    delete ui;
}
