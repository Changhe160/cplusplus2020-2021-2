#include <iostream>

//单行注释
/*多行注释：C++标准输入输出流类库，
用于std::cin&std::cout两个IO（输入和输出）对象*/


//例1.1
//int main() {   
//	return 0; /*返回一个整数值*/
//}

//例1.2 计算圆柱体体积
int main() {
	double radius, height;									// 定义三个double类型对象，存储半径、高和体积的值
	std::cout << "please input radius and height: ";		//屏幕终端显示 Please input radius and height:	
	std::cin >> radius >> height;							//从键盘输入6.5 12 
	double volume = 3.14*radius*radius*height;				//计算圆柱体体积
	std::cout << "the volume is " << volume << std::endl;	//屏幕输出 the volume is 1591.98
	return 0;
}