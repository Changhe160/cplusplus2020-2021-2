
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
		string str1;			//默认初始化，定义一个空字符串
		string str2(str1);		//等价于string str2 = str1; str2是str1的一个拷贝
		string str3 = "Rosita"; //复制初始化
		string str4("Rosita");	//直接初始化
		string str5(5, 'R');	//直接初始化，str5的内容为RRRRR
	}
	//4.5.2
	{
		string s;
		cin >> s;				//遇到空白字符停止
		cout << s;				//输出s的内容
		getline(cin, s);
		{
			string s;
			cin >> s;
			cout << s.size() << endl;	//输出s里面字符的个数，与s.length() 等价
			if (!s.empty())				//如果s 非空，则输出其内容
				cout << s;
		}
		string *ps = &s;			//定义一个指针对象指向string对象s
		cout << ps->size() << endl; //通过指针调用size成员函数
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
			s[1] = 'H';				//对第二个元素进行写操作
			cout << s.at(1) << endl;
			cout << s.front() << " " << s.back() << endl; //打印输出h o
		}
	}
	//4.5.3
	{
		char cstr[] = "Hello";
		cout << cstr << endl;

		char *ps = cstr;			//指向字符数组cstr
		const char *ps2 = "C++";

		cout << ps << "," << ps2 << endl;	//输出Hello,C++
		char cs[] = { 'C', '+ ', '+ ' };
		//cout << strlen(cs) << endl;			//错误：cs没有以空字符结束
		char small[] = "C++", big[] = "Programming";
		//cout << strcpy(small, big) << endl;	//错误：small 内存空间不足
		{
			string str = "hello";
			char carr[10];
			strcpy(carr, str.c_str());
		}
	}

	//例4.4 猜单词游戏
	{
		string target;
		cout << "请给出一个单词：";
		cin >> target;
		cout << string(100, '\n');				//通过100个换行，隐藏输入的单词
		int length = target.length();
		string attempt(length, '*'), badchars;	//分别记录当前正确的猜测和错误的猜测 	 
		int guesses = 6;						//最大尝试次数
		cout << "单词已准备好，它有" << length << "个字母:" << attempt << endl;
		do {
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos ||	//badchars或attempt中已有letters  
				attempt.find(letter) != string::npos) {		//string::npos是一个标志位 
				cout << "已经猜过该字母，请重猜" << endl;
				continue;
			}
			auto loc = target.find(letter);
			if (loc == string::npos) {
				cout << "没有此字母!" << endl;
				--guesses;
				badchars += letter;
			}
			else {
				cout << "有这个字母，继续加油!" << endl;
				do {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);		//如果找到了，则下一次搜索位置从loc+1开始 	
				} while (loc != string::npos);
			}
			cout << "你猜测的单词:" << attempt << endl;
			if (attempt != target)
				cout << "剩余" << guesses << " 次猜错机会" << endl;
		} while (guesses > 0 && attempt != target);
		if (guesses > 0)
			cout << " 成功了，恭喜你！" << endl;
		else
			cout << "对不起，失败了，下次再玩吧，单词是" << target << endl;
	}
}