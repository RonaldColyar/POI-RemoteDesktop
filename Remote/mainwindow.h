#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "newpersonpopup.h"
#include "newentrypopup.h"
#include "confirmbreachpopup.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_BreachButton_clicked();

    void on_NewEntry_clicked();

    void on_NewPerson_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
