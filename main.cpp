//course: CS216
//Project: Lab Assignment 7
//Date: 03/08/2017
//Purpose: to implement the check for matched brackets in an expression, using F-I-L-O feature of stack
//         
//Author: Jared Rigdon

/*
This uses the first in, last out stack implementation to check if the the brackets are properly matched and have the correct  amount of numbers
Any string that arent brakets will be over looked
If the string goes out of bounds, there is an exception handeler to cover that
*/

#include <iostream>
#include <string>
#include "stack.h"
#include "bound_err.h"

using namespace std;

bool valid_parentheses(const string& exp);

int main()
{
	while (true)
	{
		cout << "Please enter an expression to check: ";
		string expression;
		getline(cin, expression);

		if (expression == "Q" || expression == "q")
			break;
		try
		{
			if (valid_parentheses(expression))
				cout << "Parsing parentheses: Matched!" << endl;
			else
				cout << "Parsing parentheses: Unmatched!" << endl;
		}
		catch (bound_err &err) {
			cout << "Error: Bounds exceeded" << endl;
			cout << "Reason: " << err.get_what() << endl;
		}
		catch (...) {
			cout << "Error: Unexpected exception occurred" << endl;
		}
	}
	cout << "Thank you for using this program." << endl;
	return 0;
}

// Purpose: check if the pair of brackets match or not
// @char opening: the opening bracket
// @char closing: the closing bracket
// @bool return true if the pair of brackets match; otherwise false 
bool matched(char opening, char closing)
{
	if (opening == '(' && closing == ')')
		return true;
	if (opening == '[' && closing == ']')
		return true;
	return false;
}

// Purpose: check if the brakets in an expression are valid
// @string E: the expression to be checked 
//     const call by reference to avoid making a copy and protect the argument at the same time
// @bool return true if it is valid, otherwise false 
bool valid_parentheses(const string& E)
{
	stack S;
	for (int i = 0; i < E.length(); i++)
	{
		if (E[i] == '(' || E[i] == '[')
			S.push(E[i]);
		if (E[i] == ')' || E[i] == ']')
		{
			if (!matched(S.pop(), E[i]))
				return false;
		}
	}
	return S.isEmpty();
}

