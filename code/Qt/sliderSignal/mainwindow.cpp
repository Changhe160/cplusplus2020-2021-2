#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(ui->horizontalSlider->value());
    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));  //qt4
    connect(ui->horizontalSlider, &QSlider::valueChanged,ui->progressBar,&QProgressBar::setValue); //qt5
}

MainWindow::~MainWindow()
{
    delete ui;
}
