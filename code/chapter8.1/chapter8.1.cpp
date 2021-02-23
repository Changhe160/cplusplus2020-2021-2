#include<iostream>
#include<memory>
#include<vector>
using namespace std;

//8.1.2
void foo(int i) {
	int *p = new int(207);
	if (*p > i) return;
	delete p;
}

int main(){
	{//8.1.1
		int *pi = new int; //piָ��һ��δ��ʼ����int ���Ͷ���
	}
	{//8.1.1
		int *pi = new int(10); //piָ��Ķ����ֵΪ10
		string *ps = new string("C++"); //psָ��Ķ��������ΪC++
	}

	{//8.1.2
		int *p = new int(0);
		delete p; //p����Ϊ����new �����ڴ��ַ
	}
	{//8.1.2
		int i, *p1 = &i, *p2 = new int(10);
		//delete p1; //δ���壬p1 ָ��Ķ���Ϊ�ֲ�����
		p1 = p2; //p1��p2 ָ��ͬһ����̬�ڴ�ռ�
		delete p1; //��ȷ���ͷ�p1 ��ָ��Ķ�̬�ڴ�ռ�
				   //delete p2; //����p2 ָ��Ķ�̬�ڴ��Ѿ����ͷ�
	}
	{//8.1.2
		int *p = new int(0);
		delete p;
		p = nullptr; // p����ָ���κζ���
	}
	{//8.1.3
		int i, *q = new int(2);
		q = &i; //�����ڴ�й©
	}
	{//8.1.3
		foo(614); //��ȷ�����ڴ�й©
		foo(105); //���󣺷����ڴ�й©
	}

	{//8.1.4.1
		{
			unique_ptr<string> p1; //p1Ϊnullptr
			unique_ptr<int> p2(new int(207)); //ֱ�ӳ�ʼ����ʽ����p2
			unique_ptr<int> p3=make_unique<int>(207); //C++14 
			unique_ptr<string> p4 = make_unique<string>("C++14"); //C++14
		} //p1��p2�뿪�����򣬱����٣�ͬʱ�ͷ���ָ��Ķ�̬�ڴ�
	}
	{//8.1.4.1
		unique_ptr<string> p1(new string("Mandy")); //p1ָ��string���Ͷ���
		if (p1 && p1->empty()) //ָ��p1 �ǿ�����ָ��Ķ���Ϊ�ǿ�string
			*p1 = "Lisha"; //*p1Ϊ������
	}
	{//8.1.4.1
		unique_ptr<int> p1(new int(207));
		//unique_ptr<int> p2(p1); //����unique_ptr���ܱ�����
		unique_ptr<int> p3;
		//p3 = p2; //����unique_ptr��֧�ָ�ֵ
	}
	{//8.1.4.1
		unique_ptr<int> p1(new int(207));
		unique_ptr<int> p2(p1.release());
		cout << *p2 << endl;
		unique_ptr<int> p3(new int(105));
		p3.reset(p2.release());
		cout << *p3 << endl;
	}
	{//8.1.4.2
	 //shared_ptr<int> p1 = new int(105); //���󣺱���ʹ��ֱ�ӳ�ʼ������ʽ
		shared_ptr<int> p2(new int(614)); //��ȷ
	}
	{//8.1.4.2
	 //����һ��shared_ptr��ָ��һ��ֵΪ10��int ���Ͷ���
		shared_ptr<int> pi = make_shared<int>(10);
	}
	{//8.1.4.2
		auto pi = make_shared<int>(10);
	}
	{//8.1.4.2
		auto p1 = make_shared<int>(10); //p1ָ��Ķ���ֻ��p1 һ��������
		cout << p1.use_count() << endl; //���1
		auto p2(p1); //p1��p2 ��ָͬ��ͬһ������
		cout << p1.use_count() << endl; //���2
		auto p3 = make_shared<int>(11), p4(p3);
		cout << p4.use_count() << endl; //���2
		p3 = p1;
		cout << p4.use_count() << p1.use_count() << endl; //���1 3
	}
	{//8.1.4.3
		auto ps = make_shared<int>(10);
		weak_ptr<int> pw(ps); //ps�����ü�������ı�
		if (auto p = pw.lock())
			cout << *p;
	}
	{//8.1.5
		int n = 5;
		int *pa = new int[n];
	
		int *pa1 = new int[5]; //5��δ�����int
		int *pa2 = new int[5](); //5��ֵΪ0��int
		int *pa3 = new int[5]{ 1,2,3,4,5 };
	

		delete[] pa; //pa����Ϊָ��̬����������Ϊ��
					  //delete pa; //���󣺲���δ�������Ϊ
		delete[] pa1;
		delete[] pa2;
		delete[] pa3;
	}

}

