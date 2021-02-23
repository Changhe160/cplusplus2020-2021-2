#include <QCoreApplication>
#include<QDebug>
#include<iostream>
#include<vector>
#include<string>
#include<QString>
#include<QVector>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {//2.5.10
        int i = 0, j;
        j = i * 2 + i++;
        cout << j << endl;
    }
    vector<string> vs;
    vs.push_back("Hello");
    vs.push_back("World");
    vs.push_back("Qt!");
    for(auto &i:vs){
        cout<<i<<endl;
    }
    cout<<std::flush;

    QVector<QString> vsq;
    vsq.push_back("Hello");
    vsq.push_back("World");
    vsq.push_back("Qt!");

    for(auto &i:vsq){
        qDebug()<<i;
    }
    return a.exec();
}
