#ifndef ENTRYDETAILSVIEW_H
#define ENTRYDETAILSVIEW_H

#include <QDialog>

namespace Ui {
class EntryDetailsView;
}

class EntryDetailsView : public QDialog
{
    Q_OBJECT

public:
    explicit EntryDetailsView(QWidget *parent = nullptr);
    ~EntryDetailsView();

private:
    Ui::EntryDetailsView *ui;
};

#endif // ENTRYDETAILSVIEW_H
