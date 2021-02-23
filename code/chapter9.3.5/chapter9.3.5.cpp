
#include <string>
#include <iostream>
#include "Calculator.h"

using namespace std;

int main(){
	string exp;
	Calculator cclt;
	while (getline(cin, exp)){
		cout << cclt.doIt(exp) << endl;
	}	

	system("pause");
    return 0;
}

