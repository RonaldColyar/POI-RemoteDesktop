#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <string>
#include "main_functionality.cpp"



int main(int argc, char *argv[]){

QApplication a(argc, argv);
MainWindow w;
w.show();
return a.exec();
    return 0;

}
