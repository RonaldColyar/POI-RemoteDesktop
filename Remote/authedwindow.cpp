#include "authedwindow.h"
#include "ui_authedwindow.h"

authedwindow::authedwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authedwindow)
{
    ui->setupUi(this);
}

authedwindow::~authedwindow()
{
    delete ui;
}
