#include <iostream>

//����ע��
/*����ע�ͣ�C++��׼�����������⣬
����std::cin&std::cout����IO����������������*/


//��1.1
//int main() {   
//	return 0; /*����һ������ֵ*/
//}

//��1.2 ����Բ�������
int main() {
	double radius, height;									// ��������double���Ͷ��󣬴洢�뾶���ߺ������ֵ
	std::cout << "please input radius and height: ";		//��Ļ�ն���ʾ Please input radius and height:	
	std::cin >> radius >> height;							//�Ӽ�������6.5 12 
	double volume = 3.14*radius*radius*height;				//����Բ�������
	std::cout << "the volume is " << volume << std::endl;	//��Ļ��� the volume is 1591.98
	return 0;
}