#ifndef MYHEADER_H
#define MYHEADER_H
const double pi = 3.1415926;			//`{\color{green}const����}`
int add(int, int);	 //`{\color{green}��������}`
extern int g_sum;   //`{\color{green}ȫ�ֶ�������}`

inline bool isNumber(char ch) {     //`{\color{green} ��������}`
	return ch >= '0'&&ch <= '9' ? 1 : 0;
}
constexpr int scale() {				//`{\color{green} constexpr ����}`
	return 10;
}

class myClass {  };					// `{\color{green}�ඨ��}`

template<typename T>				// `{\color{green}����ģ��}`
const T& getMax(const T &a, const T &b) {
	return a > b ? a : b;
}
#endif // !MYHEADER_H

