#include "Foo.h"
#include "Goo.h"
#include<iostream>

int main() {
	//int x  = doSomething(2, 1);
	int x = Foo::doSomething(2, 1);
	x = Wang::Goo::doSomething(2, 1);
	
	FistVersion::fun(1);
	::fun(1);
	fun(1.0);

	using std::cout;
	cout << "Hello world";
}