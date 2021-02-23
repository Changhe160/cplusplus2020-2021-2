#ifndef NODEPAD_H
#define NODEPAD_H

#include <QMainWindow>

namespace Ui {
class Nodepad;
}

class Nodepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nodepad(QWidget *parent = nullptr);
    ~Nodepad();

private slots:
    void on_pushButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::Nodepad *ui;
};

#endif // NODEPAD_H
