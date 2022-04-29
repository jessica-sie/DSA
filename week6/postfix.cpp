#include <iostream>
#include "./stack.hpp"
#include <string>
#include <vector>

using namespace std;

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

void PostFixConverter(string infix)
{
    dsa::Stack<char> OperatorStack;

    // Initializing the Postfix Stack
    for (int i = 0; i < infix.length(); i++)
    {
        char oper = infix[i];
        // Check if its an operand and put it in result
        if (Priority(oper) == 4)
        {
            cout << oper;
        }
        else
        {
            if (OperatorStack.size >= 1 || i == infix.length() - 1)
            {
                cout << OperatorStack.pop();
                OperatorStack.push(oper);
            }
            else
            {
                OperatorStack.push(oper);
            }
        }
    }
    cout << OperatorStack.pop() << endl;
}

void PostFixConverterRecursive(string infix, int size, int inc, dsa::Stack<char> &OperatorStack)
{
    // BASE CASE
    if (inc == size - 1)
    {
        cout << OperatorStack.pop() << endl;
        return;
    }
    // LOGIC
    char oper = infix[inc];
    // if operand, put in result 
    if (Priority(oper) == 4)
    {
        cout << oper;
    }
    // if operator 
    else
    {
        // operator precedence 
        
        if (OperatorStack.size >= 1 || inc == infix.length() - 1)
        {//????
            cout << OperatorStack.pop();
            OperatorStack.push(oper);
        }
        else
        {
            OperatorStack.push(oper);
        }
    }
    PostFixConverterRecursive(infix, size, inc + 1, OperatorStack);
}

int main()
{

    dsa::Stack<char> OperatorStack;
    string infix = "4*20/30";
    // PostFixConverter(infix);
    PostFixConverterRecursive(infix, infix.length(), 0, OperatorStack);
}