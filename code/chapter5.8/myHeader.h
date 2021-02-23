#ifndef MYHEADER_H
#define MYHEADER_H
const double pi = 3.1415926;			//`{\color{green}const对象}`
int add(int, int);	 //`{\color{green}函数声明}`
extern int g_sum;   //`{\color{green}全局对象声明}`

inline bool isNumber(char ch) {     //`{\color{green} 内联函数}`
	return ch >= '0'&&ch <= '9' ? 1 : 0;
}
constexpr int scale() {				//`{\color{green} constexpr 函数}`
	return 10;
}

class myClass {  };					// `{\color{green}类定义}`

template<typename T>				// `{\color{green}函数模板}`
const T& getMax(const T &a, const T &b) {
	return a > b ? a : b;
}
#endif // !MYHEADER_H

