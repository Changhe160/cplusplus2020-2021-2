#include "nodepad.h"
#include "ui_nodepad.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
Nodepad::Nodepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nodepad)
{
    ui->setupUi(this);
}

Nodepad::~Nodepad()
{
    delete ui;
}

void Nodepad::on_pushButton_clicked()
{
    qApp->quit();
}

void Nodepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
               tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

   if (!fileName.isEmpty()) {
       QFile file(fileName);
       if (!file.open(QIODevice::ReadOnly)) {
           QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
           return;
       }
       QTextStream in(&file);
       ui->textEdit->setText(in.readAll());
       file.close();
   }
}

void Nodepad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}
