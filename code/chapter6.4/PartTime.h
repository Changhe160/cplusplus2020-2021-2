//#pragma once
#ifndef PARTTIMEWORKER__H
#define PARTTIMEWORKER__H

#include<string>
using namespace std;

//6.4.1
class PartTimeWorker {
	string m_name;
	double m_hours;
	static double ms_payRate;
	static const int ms_maxHourWeek = 20;
public:
	double salary();
	void set_hours(double h);
	static double rate() { return ms_payRate; }
	static void initRate(double rate);
	friend ostream& operator<<(ostream &o, PartTimeWorker& w);
};

ostream& operator<<(ostream &o, PartTimeWorker& w);
#endif