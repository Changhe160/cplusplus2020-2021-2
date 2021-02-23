#include "analogclock.h"

#include <QPoint>
#include<QColor>
#include<QTimer>
#include<QTime>
#include<QPainter>
AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
{
   QTimer *timer = new QTimer(this);
   //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
   connect(timer,&QTimer::timeout,this,QOverload<>::of(&AnalogClock::update));
   timer->start(200);
    // update, repaint,  region,erase
   setWindowTitle(tr("Analog Clock"));
   resize(200, 200);
}

AnalogClock::~AnalogClock()
{

}

void AnalogClock::paintEvent(QPaintEvent*){
    // list of three points for hour, minute, and second hands
    static const QPoint hourHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -60)
    };

    static const QPoint secondHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -85)
    };

    // define colors for hour and minute hands, minute hand is 75% opaque
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(0, 0, 0,220);

    //get the min size of wedget height and width
    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    //define a painter that draws on this widget
    //move origin to the middle of this widget
    //scale to proper size
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    // no outline for hour and minute hands
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    // make sure the previous rotation does not affect the
    //current rotation
    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    //draw hour markers around the edges of the colock
    painter.setPen(hourColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    //rotate the minite hand as the hour hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    //draw minite markers around the edges of the colock
    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    //rotate the second hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
