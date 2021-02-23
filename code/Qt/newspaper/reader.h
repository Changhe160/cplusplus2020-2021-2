#ifndef READER_H
#define READER_H
#include <QObject>
#include <QDebug>
class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}
public slots:
    void receiveNewspaper(const QString &name,const QDate &date)
    {
        qDebug() << "Receives Newspaper: " << name<<" "<<date;
    }
};

#endif // READER_H

