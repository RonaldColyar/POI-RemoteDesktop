#include "newpersonpopup.h"
#include "ui_newpersonpopup.h"

NewPersonPopup::NewPersonPopup(RequestManager RM,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPersonPopup)
{
    ui->setupUi(this);
}

NewPersonPopup::~NewPersonPopup()
{
    delete ui;
}
