#include "PartTime.h"
#include <iostream>


int main() {
	//6.4.2
	{
		cout << PartTimeWorker::rate() << endl; //ͨ���������ʾ�̬��Ա
		PartTimeWorker worker;
		cout << worker.rate() << endl; //ͨ��������ʾ�̬��Ա
	}
	//6.5.2
	{
		double (PartTimeWorker::*pf)();
		pf = &PartTimeWorker::salary;

		auto pf2 = &PartTimeWorker::salary;

		using PTWS = double (PartTimeWorker::*)();

		PTWS pf3 = &PartTimeWorker::salary;

		PartTimeWorker w;
		cout << w.salary() << endl;
		cout << (w.*pf)() << endl;
		cout << (w.*pf2)() << endl;
	}

}

