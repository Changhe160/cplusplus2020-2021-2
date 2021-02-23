#include<iostream>
#include<string>
#include<exception>
using namespace std;

#define glue(a,b) a##b
#define str(a) #a
#define f(...) add(__VA_ARGS__)

int add(int a, int b) {
	return a + b;
}
int add(int a, int b, int c) {
	return a + b + c;
}
void test() {

	glue(c, out) << "test" << endl;
	cout << str(test) << endl;
	cout << f(1, 1) << endl;
	cout << f(1, 1, 1) << endl;
	int glue(x, 1) = 1;
	cout << x1 << endl;
}
namespace noException {
	void foo() {
		int a[5] = {1,2,3,4,5};
		for (int i = 0; i < 5; ++i) {
			a[i] += a[i + 1];
		}
	}
}

namespace WithException {
	void foo() {
		int a[5] = { 1,2,3,4,5 };
		try {
			for (int i = 0; i < 5; ++i) {
				if (i > 3)
					throw string("outof range error");
				a[i] += a[i + 1];
			}
		}
		
		catch (const string & err) {
			std::cerr << err << endl;
		}
	}
}

double divide(int a, int b){
	if (b == 0)
		throw "Division by zero condition!";
	return a / b;
}

struct MyException :public exception {
	const char* what() const noexcept { 
		return "Ooops!"; 
	}
};

int main() {

	try {
		throw MyException();
	}
	catch (exception& ex) {
		cerr << ex.what() << endl;
	}


	int a = 1, b = 0;
	try {
		int c = divide(a, b);
	}
	catch (const string & str) {
		cerr << str << endl;
	}
	catch (const char* str) {
		cerr << str << endl;
	}
	WithException::foo();
	//WithoutException::foo();

}