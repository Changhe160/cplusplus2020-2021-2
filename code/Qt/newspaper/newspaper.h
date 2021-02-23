#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include <QObject>
#include<QDate>
////////// newspaper.h
class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString &name,const QDate &date=QDate::currentDate()) :
        m_name(name),m_date(date)
    {
    }
    void send()
    {
        emit newPaper(m_name,m_date);
    }
signals:
    void newPaper(const QString &name, const QDate &date);
private:
    QString m_name;
    QDate m_date;
};
#endif // NEWSPAPER_H

