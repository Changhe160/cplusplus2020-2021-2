#include "Stack.h"
#include "Calculator.h"
int main() {

	string exp;
	Calculator cclt;
	while (getline(cin, exp) ){
		cout << exp << cclt.doIt(exp) << endl;
	}
	
	system("pause");

}