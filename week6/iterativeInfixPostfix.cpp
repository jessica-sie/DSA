// converting infix expression to postfix iterative method
#include <iostream>
#include <string>
#include <stack> // C++ built in stack operations
using namespace std;

// function to return precedence of operators MDAS
int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '/' || c=='*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// function to convert infix to postfix
void infixToPostfix(string s) {

	stack<char> st; 
	string result;

	for(int i = 0; i < s.length(); i++) {
		char c = s[i];

		// if scanned character is an operand => add to output string
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		// if the scanned character is a ‘(‘ => push to stack
		else if(c == '(')
			st.push('(');

		// if the scanned character is a ‘)’ => pop to output string from the stack until ‘(‘ found
		else if(c == ')') {
			while(st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		// if operator is scanned
		else {
			while(!st.empty() && prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all remaining elements from the stack
	while(!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout <<"postfix: "<< result << endl;
}

// main driver
int main() {
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "infix: " << exp << endl;
	infixToPostfix(exp);

    exp = "(A/(B-C)*D+E)";
    cout << "infix: " << exp << endl;
	infixToPostfix(exp);
    

	return 0;
}
