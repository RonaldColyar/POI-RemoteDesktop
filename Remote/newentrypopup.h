#ifndef NEWENTRYPOPUP_H
#define NEWENTRYPOPUP_H

#include <QDialog>
#include "main_functionality.h"
namespace Ui {
class NewEntryPopup;
}

class NewEntryPopup : public QDialog
{
    Q_OBJECT

public:
    explicit NewEntryPopup(RequestManager RM,QWidget *parent = nullptr);
    ~NewEntryPopup();

private:
    Ui::NewEntryPopup *ui;
};

#endif // NEWENTRYPOPUP_H
