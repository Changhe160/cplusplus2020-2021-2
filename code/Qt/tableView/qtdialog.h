#ifndef QTDIALOG_H
#define QTDIALOG_H

#include <QDialog>

namespace Ui {
  class QtDialog;
}

struct QStandardItemModel;

class QtDialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit QtDialog(QWidget *parent = 0);
  ~QtDialog();
  
private slots:
  void on_button_clicked();

private:
  Ui::QtDialog *ui;
};

#endif // QTDIALOG_H
