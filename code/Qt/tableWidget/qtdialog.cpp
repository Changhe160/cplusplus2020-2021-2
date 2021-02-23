#include "qtdialog.h"

#include <string>
#include <sstream> // for stringstream

#include "ui_qtdialog.h"

QtDialog::QtDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtDialog)
{
  ui->setupUi(this);

  QTableWidget * const t = ui->tableWidget;
  const int n_rows = t->rowCount();
  const int n_cols = t->columnCount();
  QStringList header;
  header<<"X"<<"Y";
  t->setHorizontalHeaderLabels(header);
  t->setRowCount(9);
  for (int x=0; x!=n_cols; ++x)
  {
    for (int y=0; y!=n_rows; ++y)
    {
      std::stringstream s ;
      s<< "(" <<(x)<<","<<(y)<<+ ")";
      QTableWidgetItem * const i = new QTableWidgetItem(QString(s.str().c_str()));
      t->setItem(y, x, i);
    }
  }
}

QtDialog::~QtDialog()
{
  delete ui;
}

void QtDialog::changeEvent(QEvent *e)
{
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}
