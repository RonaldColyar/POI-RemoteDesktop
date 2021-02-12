#include "newentrypopup.h"
#include "ui_newentrypopup.h"


NewEntryPopup::NewEntryPopup(RequestManager RM, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryPopup)
{
    ui->setupUi(this);
}

NewEntryPopup::~NewEntryPopup()
{
    delete ui;
}
