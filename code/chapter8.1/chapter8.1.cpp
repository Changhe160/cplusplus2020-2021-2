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
		int *pi = new int; //pi指向一个未初始化的int 类型对象
	}
	{//8.1.1
		int *pi = new int(10); //pi指向的对象的值为10
		string *ps = new string("C++"); //ps指向的对象的内容为C++
	}

	{//8.1.2
		int *p = new int(0);
		delete p; //p必须为利用new 分配内存地址
	}
	{//8.1.2
		int i, *p1 = &i, *p2 = new int(10);
		//delete p1; //未定义，p1 指向的对象为局部对象
		p1 = p2; //p1和p2 指向同一个动态内存空间
		delete p1; //正确，释放p1 所指向的动态内存空间
				   //delete p2; //错误：p2 指向的动态内存已经被释放
	}
	{//8.1.2
		int *p = new int(0);
		delete p;
		p = nullptr; // p不再指向任何对象
	}
	{//8.1.3
		int i, *q = new int(2);
		q = &i; //发生内存泄漏
	}
	{//8.1.3
		foo(614); //正确：无内存泄漏
		foo(105); //错误：发生内存泄漏
	}

	{//8.1.4.1
		{
			unique_ptr<string> p1; //p1为nullptr
			unique_ptr<int> p2(new int(207)); //直接初始化方式创建p2
			unique_ptr<int> p3=make_unique<int>(207); //C++14 
			unique_ptr<string> p4 = make_unique<string>("C++14"); //C++14
		} //p1和p2离开作用域，被销毁，同时释放其指向的动态内存
	}
	{//8.1.4.1
		unique_ptr<string> p1(new string("Mandy")); //p1指向string类型对象
		if (p1 && p1->empty()) //指针p1 非空且其指向的对象为非空string
			*p1 = "Lisha"; //*p1为解引用
	}
	{//8.1.4.1
		unique_ptr<int> p1(new int(207));
		//unique_ptr<int> p2(p1); //错误：unique_ptr不能被拷贝
		unique_ptr<int> p3;
		//p3 = p2; //错误：unique_ptr不支持赋值
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
	 //shared_ptr<int> p1 = new int(105); //错误：必须使用直接初始化的形式
		shared_ptr<int> p2(new int(614)); //正确
	}
	{//8.1.4.2
	 //定义一个shared_ptr，指向一个值为10的int 类型对象
		shared_ptr<int> pi = make_shared<int>(10);
	}
	{//8.1.4.2
		auto pi = make_shared<int>(10);
	}
	{//8.1.4.2
		auto p1 = make_shared<int>(10); //p1指向的对象只有p1 一个引用者
		cout << p1.use_count() << endl; //输出1
		auto p2(p1); //p1和p2 共同指向同一个对象
		cout << p1.use_count() << endl; //输出2
		auto p3 = make_shared<int>(11), p4(p3);
		cout << p4.use_count() << endl; //输出2
		p3 = p1;
		cout << p4.use_count() << p1.use_count() << endl; //输出1 3
	}
	{//8.1.4.3
		auto ps = make_shared<int>(10);
		weak_ptr<int> pw(ps); //ps的引用计数不会改变
		if (auto p = pw.lock())
			cout << *p;
	}
	{//8.1.5
		int n = 5;
		int *pa = new int[n];
	
		int *pa1 = new int[5]; //5个未定义的int
		int *pa2 = new int[5](); //5个值为0的int
		int *pa3 = new int[5]{ 1,2,3,4,5 };
	

		delete[] pa; //pa必须为指向动态分配的数组或为空
					  //delete pa; //错误：产生未定义的行为
		delete[] pa1;
		delete[] pa2;
		delete[] pa3;
	}

}

