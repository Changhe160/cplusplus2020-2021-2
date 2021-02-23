#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_dlg;
}

void MainWindow::on_actionNew_Dialog_triggered()
{

    //QDialog mydlg;
    //mydlg.exec();

    //mydlg.show();

    //m_dlg=new QDialog(this);
    m_dlg=new QDialog();
    //m_dlg->setModal(true);
    m_dlg->setAttribute(Qt::WA_DeleteOnClose);
    m_dlg->show();
}
