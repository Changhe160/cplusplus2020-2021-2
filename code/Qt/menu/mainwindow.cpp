#include "mainwindow.h"
#include <QMenu>
#include<QMenuBar>
#include<QToolBar>
#include<QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Simple Menu");
    QAction *action_quit = new QAction(QIcon(":/images/icons/quit.png"),"&Quit",this);
   // QAction *action_quit = new QAction("&Quit",this);

    action_quit->setStatusTip("quit app");

    QMenu *menu_file=menuBar()->addMenu("&File");
    menu_file->addAction(action_quit);

    QToolBar *toolbar= addToolBar("&File");
    toolbar->addAction(action_quit);

    connect(action_quit,&QAction::triggered,qApp, &QApplication::quit);

    QAction *action_open =new QAction(QIcon(":/images/open"),tr("&Open"),this);
    //QAction *action_open =new QAction(tr("&Open"),this);
   // action_open->setShortcut(QKeySequence::Open);
    action_open->setShortcut(QKeySequence(tr("Ctrl+O")));
    menu_file->addAction(action_open);
    toolbar->addAction(action_open);
    connect(action_open,&QAction::triggered,this, &MainWindow::open);
}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
    //QMessageBox::information(this, tr("Information"), tr("Open"));
    QDialog dialog(this);
    dialog.resize(320,180);
    dialog.setWindowTitle(tr("Hello, dialog!"));
    dialog.exec();
    //dialog.show();

    /*QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(tr("Hello, dialog!"));
    //dialog->setModal(true);
    dialog->show();*/
}

