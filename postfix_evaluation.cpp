//Write a program for the evaluation of a Postfix expression. 
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#define size 50
using namespace std;
char stack[size];
int top = -1;
void push(char n)
{
    if (top == size - 1)
    {
        cout << "\nSorry! Stack is full";
    }
    else
    {
        top++;
        stack[top] = n;
    }
}
char pop()
{
    char x;
    if (top == -1)
    {
        cout << "\nStack got empty";
        return '\0';
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}
int precedence(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '*' || a == '/' || a == '%')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string postfix(string s)
{
    int i = 0;
    string a = "";
    top = -1;   
    while (i < s.length())
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            while (top != -1 && stack[top] != '(' && stack[top] != '[' && stack[top] != '{')
            {
                a = a + pop();
                a = a + " ";
            }
            if (top != -1)
            {
                pop();
            }
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^')
        {
            if (top == -1)
            {
                push(s[i]);
            }
            else if (stack[top] == '(' || stack[top] == '[' || stack[top] == '{')
            {
                push(s[i]);
            }
            else if (precedence(s[i]) > precedence(stack[top]) || (s[i] == '^' && precedence(s[i]) == precedence(stack[top])))
            {
                push(s[i]);
            }
            else
            {
                while (top != -1 && stack[top] != '(' && stack[top] != '[' && stack[top] != '{' && precedence(stack[top]) >= precedence(s[i]))
                {
                    a = a + pop();
                    a = a + " ";
                }
                push(s[i]);
            }
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            {
                a = a + s[i];
                i++;
            }
            a = a + " ";
            continue;
        }
        i++;
    }
    while (top != -1)
    {
        a = a + pop();
        a = a + " ";
    }
    return a;
}
int evalStack[size];
int evalTop = -1;
void pushEval(int n)
{
    if (evalTop == size - 1)
    {
        cout << "\nEvaluation stack is full";
    }
    else
    {
        evalTop++;
        evalStack[evalTop] = n;
    }
}
int popEval()
{
    if (evalTop == -1)
    {
        cout << "\nEvaluation stack is empty";
        return 0;
    }
    else
    {
        int x = evalStack[evalTop];
        evalTop--;
        return x;
    }
}
int evaluate(string s)
{
    evalTop = -1;   
    string token;
    stringstream ss(s);
    while (ss >> token)
    {
        if (token[0] >= '0' && token[0] <= '9')
        {
            int n = stoi(token);
            pushEval(n);
        }
        else
        {
            int b = popEval();
            int a = popEval();
            int result;
            switch (token[0])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                case '^':
                    result = pow(a, b);
                    break;

                default:
                    result = 0;
            }

            pushEval(result);
        }
    }
    return popEval();
}
int main()
{
    string s1;
    string p;
    cout << "\nEnter one Infix expression: ";
    cin >> s1;
    p = postfix(s1);
    cout << "\nPostfix Expression is\n";
    cout << p;
    int result = evaluate(p);
    cout << "\n\nResult = " << result;
    return 0;
}
