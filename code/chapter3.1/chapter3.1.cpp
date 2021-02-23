#include<iostream>
using namespace std;

int main(){

	{//3.1.1节
		int counter = 0;
		//counter + 1; //一条没有实际意义的表达式语句
		counter += 1; //一条有用的复合赋值语句
		; //空语句
		counter += 1;; //第二个分号不会影响该语句的执行
	}

	{//3.1.1节
		int counter = 0;
		//while (counter < 10); //一个多余的分号导致程序死循环
		++counter;
	}

	//3.1.2节
	{ //语句块开始
		int sum = 0; // 定义一个对象
					/*...*/
	} //语句块结束

	{//3.1.3节
		int counter = 0, sum = 0;
		while (counter < 10) { //while作用域从这里开始
			++counter;
			sum += counter;
		} //while作用域到这里结束
	}

}