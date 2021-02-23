#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Newspaper newspaper("Newspaper A");
    Reader reader;
    //QObject::connect(&newspaper,SIGNAL(newPaper(QString,QDate)),&reader,SLOT(receiveNewspaper(QString,QDate)));
    QObject::connect(&newspaper,&Newspaper::newPaper,&reader,&Reader::receiveNewspaper);

    newspaper.send();

    return app.exec();
}
