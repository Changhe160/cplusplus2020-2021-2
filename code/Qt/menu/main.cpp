#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(800,600);
   // w.setWindowTitle("Simple Menu");
    w.show();
    return a.exec();
}
