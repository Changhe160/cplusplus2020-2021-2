//8.2.1�� ���ַ�����
#include<iostream>

using namespace std;

class MyStr {
	int m_length; // �ַ�����ĳ���
	char *m_buff; // ָ��̬�ַ�����
public:
	MyStr(const char* val = nullptr); //Ĭ�Ϲ��캯��
	~MyStr() { delete[] m_buff; }
	int size() { return m_length; }

	//8.2.2��
	MyStr(const MyStr &rhs);
	//8.2.2��
	MyStr& operator=(const MyStr &rhs);

	//8.2.3��
	MyStr(MyStr &&rhs);
	MyStr& operator=(MyStr &&rhs);

	//������������
	friend ostream& operator<<(ostream &, const MyStr &);//��ӡ�ַ���
	friend MyStr operator+(const MyStr &, const MyStr &);//�ַ������
private: //˽�о�̬��Ա����
	static int strlen(const char *ptr); //��ȡC����ַ����ĳ���
	//����srcָ���������ǰn ���ַ���destָ���������
	static void strncpy(char *dest, const char *src, int n);
};



