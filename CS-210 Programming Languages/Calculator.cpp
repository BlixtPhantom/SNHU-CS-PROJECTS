/*
 * Calculator.cpp
 *
 *  Date: [Enter date]
 *  Author: [Your Name]
 */

#include <iostream>

using namespace std;

int main() {
	char statement[100];
	int op1, op2;
	string operation;
	string answer = "y";
	while (answer == "y") {
		cout << "Enter expression" << endl;
		cin >> op1 >> operation >> op2;
		if (operation == "+"){
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
		}
		else if (operation == "-"){
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
		}
		else if (operation == "*") {
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
		}
		else if (operation == "/") {
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
	    } else {
			break;
		}

		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;

		return 0;
	}
}







