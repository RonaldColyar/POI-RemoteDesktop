#ifndef NEWPERSONPOPUP_H
#define NEWPERSONPOPUP_H

#include <QDialog>
#include "main_functionality.h"

namespace Ui {
class NewPersonPopup;
}

class NewPersonPopup : public QDialog
{
    Q_OBJECT

public:
    explicit NewPersonPopup(RequestManager RM,QWidget *parent = nullptr);
    ~NewPersonPopup();

private:
    Ui::NewPersonPopup *ui;
};

#endif // NEWPERSONPOPUP_H
