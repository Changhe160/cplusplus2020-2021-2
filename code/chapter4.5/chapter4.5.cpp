
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <vector>
#include<fstream>
#include <string>  
#include<cstring>
using namespace std;


int main() {

	//4.5.1
	{
		string str1;			//Ĭ�ϳ�ʼ��������һ�����ַ���
		string str2(str1);		//�ȼ���string str2 = str1; str2��str1��һ������
		string str3 = "Rosita"; //���Ƴ�ʼ��
		string str4("Rosita");	//ֱ�ӳ�ʼ��
		string str5(5, 'R');	//ֱ�ӳ�ʼ����str5������ΪRRRRR
	}
	//4.5.2
	{
		string s;
		cin >> s;				//�����հ��ַ�ֹͣ
		cout << s;				//���s������
		getline(cin, s);
		{
			string s;
			cin >> s;
			cout << s.size() << endl;	//���s�����ַ��ĸ�������s.length() �ȼ�
			if (!s.empty())				//���s �ǿգ������������
				cout << s;
		}
		string *ps = &s;			//����һ��ָ�����ָ��string����s
		cout << ps->size() << endl; //ͨ��ָ�����size��Ա����
		string s1 = "Hello C++";
		string s2 = "Hello";
		string s3 = "Hi";
		{
			string s1 = "Hello ", s2 = "C++";
			string s3 = s1 + s2;
			s1 += s2;
			string s4 = "Hello " + s2;
		}
		{
			string s = "hello";
			s[1] = 'H';				//�Եڶ���Ԫ�ؽ���д����
			cout << s.at(1) << endl;
			cout << s.front() << " " << s.back() << endl; //��ӡ���h o
		}
	}
	//4.5.3
	{
		char cstr[] = "Hello";
		cout << cstr << endl;

		char *ps = cstr;			//ָ���ַ�����cstr
		const char *ps2 = "C++";

		cout << ps << "," << ps2 << endl;	//���Hello,C++
		char cs[] = { 'C', '+ ', '+ ' };
		//cout << strlen(cs) << endl;			//����csû���Կ��ַ�����
		char small[] = "C++", big[] = "Programming";
		//cout << strcpy(small, big) << endl;	//����small �ڴ�ռ䲻��
		{
			string str = "hello";
			char carr[10];
			strcpy(carr, str.c_str());
		}
	}

	//��4.4 �µ�����Ϸ
	{
		string target;
		cout << "�����һ�����ʣ�";
		cin >> target;
		cout << string(100, '\n');				//ͨ��100�����У���������ĵ���
		int length = target.length();
		string attempt(length, '*'), badchars;	//�ֱ��¼��ǰ��ȷ�Ĳ²�ʹ���Ĳ²� 	 
		int guesses = 6;						//����Դ���
		cout << "������׼���ã�����" << length << "����ĸ:" << attempt << endl;
		do {
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos ||	//badchars��attempt������letters  
				attempt.find(letter) != string::npos) {		//string::npos��һ����־λ 
				cout << "�Ѿ��¹�����ĸ�����ز�" << endl;
				continue;
			}
			auto loc = target.find(letter);
			if (loc == string::npos) {
				cout << "û�д���ĸ!" << endl;
				--guesses;
				badchars += letter;
			}
			else {
				cout << "�������ĸ����������!" << endl;
				do {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);		//����ҵ��ˣ�����һ������λ�ô�loc+1��ʼ 	
				} while (loc != string::npos);
			}
			cout << "��²�ĵ���:" << attempt << endl;
			if (attempt != target)
				cout << "ʣ��" << guesses << " �β´����" << endl;
		} while (guesses > 0 && attempt != target);
		if (guesses > 0)
			cout << " �ɹ��ˣ���ϲ�㣡" << endl;
		else
			cout << "�Բ���ʧ���ˣ��´�����ɣ�������" << target << endl;
	}
}