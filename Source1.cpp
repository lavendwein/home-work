#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

using namespace std;

int priority(char c) {
	if (c == '+' || c == '-')
		return 0;
	else if (c == '*' || c == '/')
		return 1;
	else if (c == '^')
		return 2;
	else
		return -1;
}

int main() 
{
	string str;
	string out = "";
	stack <char> stack_1;
	getline(cin, str);
	for (int i = 0; i < str.length(); ++i) {
		if (isdigit(str[i])) {
			out += str[i];
		}
		else  {	
			if (str[i] == '(') {
				stack_1.push(str[i]);
				continue;
			}
			if (str[i] == ')') {
				while (stack_1.top() != '(') {
					out += stack_1.top();
					stack_1.pop();
				}
				stack_1.pop();
				continue;
			}
			if (stack_1.size() != 0) {
				if (priority(str[i]) <= priority(stack_1.top())) {
					out += stack_1.top();
					cout << stack_1.top() << endl;
					stack_1.pop();
					stack_1.push(str[i]);
					continue;
				}
			}
			stack_1.push(str[i]);
		}
	}
	while (stack_1.size() > 0) {
		out += stack_1.top();
		stack_1.pop();
	}
	cout << out << endl;
}
