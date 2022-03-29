// converting infix expression to postfix recursive
#include <iostream>
#include "./stack.hpp"
#include <string>
using namespace std;

// operator precedence function
int Priority(char c)
{
    switch (c)
    {
    case '^':
        return 1;
        break;

    case '*':
        return 2;
        break;

    case '/':
        return 2;
        break;

    case '+':
        return 3;
        break;

    case '-':
        return 3;
        break;
    default:
        return 4;
        break;
    }
}

// recursive function infix to postfix 
void ITP(string infix, int len, int i, dsa::Stack<char> &st){

    // base case - stops the recursion when i is at the last character of string 
    if (i == len-1){
        cout <<st.pop() <<endl;
        return; // break?

    }
    // general case - reduced to base case ?
    char current = infix[i]; // storing current character in variable, for ease of access

    // if current is operand, put in result
    if(Priority(current) == 4){
        cout << current;
    }
    // if not operand (ie. is operator), check operator precedence
    else{
        // if there already an operator in stack OR if expression ending
        if(st.size >= 1 || i == infix.length()){
             
            cout << st.pop();// rm from stack
            st.add(current);// add current to stack

        }
        // if no operator
        else{
            st.add(current);
        }

    }
    ITP(infix,len,i++, st); // calling function for the next char in infix string 
}

int main(){
    dsa::Stack<char> st;
    string infix = "A+B";

    ITP(infix, infix.length(), 0, st);
}