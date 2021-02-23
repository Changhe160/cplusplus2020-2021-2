#include<iostream>
#include<string>

using namespace std;

//9.3.1
class Shape {
protected:
	string m_name;
public:
	Shape(const string &name = "") :m_name(name) {
	}
	virtual double area() const = 0;
	virtual ~Shape() {
		cout << "Destr of Shape" << endl;
	}
	const string& name() { return m_name; }
};

class Circle :public Shape {
private:
	double m_rad;
public:
	Circle(double r=0, const string &name = ""):Shape(name),m_rad(r){
	}
	double area() const {
		return 3.1415926*m_rad*m_rad;
	}
	~Circle() {
		cout << "Destr of Circle" << endl;
	}
};

class Square :public Shape {
private:
	double m_len;
public:
	Square(double l = 0, const string &name = "") :Shape(name), m_len(l) {
	}
	double area()const {
		return m_len*m_len;
	}
};

bool operator>(const Shape& s1,const Shape& s2)  {
	return s1.area() > s2.area();
}
/*
struct B
{
	virtual void fun1(int = 0) {}
	virtual void fun2() {}
	void fun3() {}
};

struct D1:public B
{
	void fun1() override {}
	void fun2() final {}
	void fun3() override {}
};

struct D2 :public D1
{
	void fun2() {}
};
*/


//9.3.4
class Mamal {
protected:
	string m_name;
public:
	virtual void sounding() = 0;
};

class Dog :public Mamal {
protected:
	void bark() {
		cout << "barking" << endl;
	}
public:
	void sounding() override {
		bark();
	}
};

class Cat :public Mamal {
protected:
	void meow() {
		cout << "meowing" << endl;
	}
public:
	void sounding() override {
		meow();
	}
};


int main() {
	Shape *p;
	//cout << p->area() << endl;
	Circle c1(1), c2(2);
	
	Square s1(1), s2(2);
	p = &s1;
	cout << p->area() << endl;

	if (c1 > s2) {
	
	}
	p = new Circle();
	delete p;

	//9.3.4
	{
		Cat c;
		c.sounding();
	}
}

