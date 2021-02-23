#include "PartTime.h"
#include <iostream>

double PartTimeWorker::ms_payRate = 7.53;
const int PartTimeWorker::ms_maxHourWeek;


void PartTimeWorker::initRate(double rate) {
	ms_payRate = rate;
}

double PartTimeWorker::salary() { 
	return m_hours * ms_payRate; 
}

void PartTimeWorker::set_hours(double h) {
	m_hours = h;
}

//6.5.1
ostream& operator<<(ostream &o, PartTimeWorker& w) {
	string PartTimeWorker::*p1 = &PartTimeWorker::m_name;
	auto p2 = &PartTimeWorker::m_name;

	PartTimeWorker *w2 = &w;
	o << w.m_name << endl;
	o << w.*p1 << endl;
	o << w2->*p2 << endl;

	return o;
}