#include <typeinfo>
#include<iostream>
struct Base{
	virtual ~Base() {}
};

struct Derived:Base{
	void name() {}
};

int main() {

	Base *b1 = new Base;

	if (Derived *d = dynamic_cast<Derived*>(b1)) 
		d->name();

	Base *b2 = new Derived;

	if (Derived *d = dynamic_cast<Derived*>(b2))
		d->name();

	try {
		Derived &d = dynamic_cast<Derived&>(*b1);
	}catch(std::bad_cast){
		std::cout << "cast failed" << std::endl;
	}

	{
		Derived *d = new Derived; 
		Base *b = d; 
		if (typeid(*d) == typeid(*b)) { }
		if (typeid(*b) == typeid(Derived)) {}
	}
}