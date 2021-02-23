#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = 0);
    ~AnalogClock();
protected:
    void paintEvent(QPaintEvent*) Q_DECL_OVERRIDE;
};

#endif // ANALOGCLOCK_H
