#include<iostream>
#include<string>
using namespace std;
#define CODE 1

class Animal {
protected:
	int m_age;
public:
	Animal(int n = 0) :m_age(n) {
		cout << "Constructor of Animal" << endl;
	}
	virtual void eat() {};
};
#if (CODE==1)
class WingedAnimal: virtual public Animal {
public:
	virtual void flap() {}
};

class Mammal : virtual public Animal {
public:
	virtual void feedMilk() {}
};
#elif(CODE==2) 
class WingedAnimal : public Animal {
public:
	virtual void flap() {}
};

class Mammal :  public Animal {
public:
	virtual void feedMilk() {}
};
#else
class WingedAnimal {
public:
	virtual void flap() {}
};

class Mammal {
public:
	virtual void feedMilk() {}
};
#endif // want_virtual



class Bat : public Mammal, public WingedAnimal {
public:
	Bat() :Mammal(), WingedAnimal(){}
};

class BBat:public Bat {
public:
	BBat():Animal(1) {}
};

int main() {
	/*Bat b;
	b.feedMilk();
	b.flap();

	b.eat();
	Animal a = b;*/
	BBat bb;
}