#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include<limits>
using namespace std;
//ostream print(ostream) {}

int main() {
	{
		ifstream in1, in2; //���������ļ����������󣨼�10.3.1�ڣ���220ҳ��
		//in1 = in2; //���󣺲��ܶ�������ֵ
		//ostream print(ostream); //����ostream ����֧�ָ���
		//print(std::cout);
	}

	{
		double x;
		cin >> x;

		//while (cin >> x);

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
			
		cin >> x;
		cout << x << endl;
	}

	{
		cout << "endl" << endl; //���endl��һ�����У�Ȼ��ˢ�»�����
		cout << "flush" << flush; //���flush���޶����ַ�����Ȼ��ˢ�»�����
		cout << "ends" << ends; //���ends��һ�����ַ�����\0������Ȼ��ˢ�»�����
	}

}