#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <string>
#include "main_functionality.cpp"



int main(int argc, char *argv[])

{

    RequestManager request_manager;
    static std::string code  = 0;
    std::string code_input;
    std::cout << "???";
    std::cin>> code_input;

    //server response
    std::string response = request_manager.auth_manager.send_code(code_input);
    if(response == "success"){
        //todo:close socket connection from request manager
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
    else{
        std::cout << "?";
    }

}
