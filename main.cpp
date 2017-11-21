//
// Created by Bychin on 17.11.2017.
//

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("C:\\Users\\Bychin\\Documents\\_Projects\\QtProjects\\build-simple_calculator-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\logo.png"));

    MainWindow window;
    window.show();

    return a.exec();
}
