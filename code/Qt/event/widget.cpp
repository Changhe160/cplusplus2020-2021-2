#include "widget.h"
#include <QMoveEvent>

#include <QApplication>
#include <QKeyEvent>


#include <QHBoxLayout>
#include <QTime>

#include<QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
     m_hbox = new QHBoxLayout(this);
     m_hbox->setSpacing(5);

     m_label = new QLabel("", this);
     m_hbox->addWidget(m_label, 0, Qt::AlignLeft | Qt::AlignTop);

     m_button=new QPushButton("PushButton",this);
     m_hbox->addWidget(m_button,0,Qt::AlignLeft | Qt::AlignTop);

     connect(m_button,&QPushButton::clicked,this,&Widget::onButtonCliecked);

     QTime qtime = QTime::currentTime();
     QString stime = qtime.toString();
     m_label->setText(stime);

     startTimer(1000);

}

Widget::~Widget()
{
    delete m_label;
    delete m_button;
    delete m_hbox;
}

void Widget::onButtonCliecked()
{
    QMessageBox msgBox;
    msgBox.setText("You clicked this.");
    msgBox.exec();
}

void Widget::moveEvent(QMoveEvent *e) {

  int x = e->pos().x();
  int y = e->pos().y();

  QString text = QString::number(x) + "," + QString::number(y);

  setWindowTitle(text);
}

void Widget::keyPressEvent(QKeyEvent *event) {

   if (event->key() == Qt::Key_Escape) {
       qApp->quit();
   }
}


void Widget::timerEvent(QTimerEvent *e) {

  Q_UNUSED(e);

  QTime qtime = QTime::currentTime();
  QString stime = qtime.toString();
  m_label->setText(stime);
}
