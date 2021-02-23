#include "qtdialog.h"

#include <cassert>

#include <QStandardItemModel>
#include "ui_qtdialog.h"

QtDialog::QtDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtDialog)
{
  ui->setupUi(this);

  ui->table->setModel(new QStandardItemModel(this));

  dynamic_cast<QStandardItemModel*>(ui->table->model())->setColumnCount(3);

  for (int i=0; i!=10; ++i) on_button_clicked();
}

QtDialog::~QtDialog()
{
  delete ui;
}

void QtDialog::on_button_clicked()
{
  const int n_cols = ui->table->model()->columnCount();
  QList<QStandardItem*> items;
  for (int i=0; i!=n_cols; ++i)
  {
    QStandardItem * const item = new QStandardItem;
    item->setText("");
    items.push_back(item);
  }
  const int j = (std::rand() >> 4) % n_cols;
  items[j]->setText("X");

  dynamic_cast<QStandardItemModel*>(ui->table->model())->appendRow(items);

  ui->table->scrollToBottom();
  ui->table->setCurrentIndex(items[j]->index());
  ui->table->edit(items[j]->index());
}
