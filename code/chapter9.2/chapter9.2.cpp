#include<iostream>
#include<string>

using namespace std;

class Person {
protected:
	string m_name;
	int m_age;
public:
	const string& name() const{		return m_name;	}
	int age() const{ return m_age; }
	void plusOneYear() { ++m_age; }
	Person(const string &name = "", int age = 0) :m_name(name), m_age(age) {
		cout << "Constr of Person" << endl;
	}
	virtual ~Person(){
		cout << "Destr of Person" << endl;
	}
	Person(Person&& rhs):m_name(std::move(rhs.m_name)),m_age(std::move(rhs.m_age)){
		cout << "move constr person" << endl;
	};
	Person& operator=(const Person&) = default;
	Person(const Person&) = default;
};

class Course {
	string m_name;
	int m_score;
public:
	Course(const string &name = "", int score = 0) :m_name(name), m_score(score) {	}
	Course(const Course &rhs) :m_name(rhs.m_name), m_score(rhs.m_score) {
		cout << "Copy constr of Course" << endl;
	}
	~Course() {
		cout << "Destr of Course" << endl;
	}
	Course(Course &&rhs) :m_name(std::move(rhs.m_name)), m_score(std::move(rhs.m_score)) {
	
	}
	void setScore(int score) {		m_score = score;	}
	int score() const{ return m_score; }
	const string& name()const { return m_name; }
};

class Student :public Person {
private:
	Course m_course;
public:

	using Person::m_age;

	Student(const string &name, int age, const Course &c) :Person(name, age), 
		m_course(c) {
		cout << "Constr of Student" << endl;
	}
	Student(const Student &rhs) :Person(rhs), m_course(rhs.m_course) {
		cout << "copy constr" << endl;
	}
	Student(Student &&rhs) : m_course(std::move(rhs.m_course)) {//Person(std::move(rhs)),
		cout << "move constr" << endl;
	}

	Course& course() {
		return m_course;
	}
	~Student() {
		cout << "Destr of Student" << endl;
	}
};

class PartTimeWorker:public Person {
	double m_hour;
	static double ms_payRate;
public:
	PartTimeWorker(const string &name, int age, double h = 0) :Person(name, age), m_hour(h) {}
	void setHours(double h) {
		m_hour = h;
	}
	double salary() {
		return m_hour*ms_payRate;
	}
};
double PartTimeWorker::ms_payRate = 7.53;

class Base {
private:
	int m_i;
protected:
	int m_j;
	int m_d;
public:
	void foo() {}
};
class PubDeriv :public Base {
private:
	int m_d;
public:
	using Base::foo;
	int foo(int) {
		//m_i = 10;//
		m_j = 1; //正确
		return m_d;
	}
};

class PriDeriv :private Base {
private:
	int m_d;
public:
	
	void foo() {
		//m_i = 10;//
		m_j = 1; //正确
	}
};

void test() {
	Base b;
	//b.m_j = 10;
	PubDeriv d;
	d.foo(10);
	d.foo();
	d.Base::foo();
}

Student foo() {
	Student s("Kevin", 19, Course("Math"));
	return s;
	//return Student("Kevin", 19, Course("Math"));
}
int main() {
	Course c("Math");
	{
		Student s("Kevin", 19, c);
		Student s2(foo());
		s.m_age = 10;
	}
	//s.plusOneYear();	
	//s.course().setScore(75);
	//cout << s.name() << " " << s.course().name()<<" "<<s.course().score() << endl;

	//PartTimeWorker w("John", 35);
	//w.setHours(5.5);
	//cout<<w.name()<<" salary: "<<w.salary() << endl;

}