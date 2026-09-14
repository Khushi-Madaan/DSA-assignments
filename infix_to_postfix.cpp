//W.A.P. to convert an infix expression to postfix expression.
#include<iostream>
#include<string>
# define size 50
using namespace std;
char stack[size];
int top=-1;
void push(char n)
{
    if(top==(size-1))
    {
        cout<<"\nSorry! Stack is full";
    }
    else
    {
        top++;
        stack[top]=n;
    }
}
string pop()
{
    string x;
    if(top==-1)
    {
        cout<<"\nStack got empty";
    }
    else
    {
       x=stack[top];
       top--;
       return x;
    }
}
int precedence(char a)
{
    if(a=='^')
    {
        return 3;
    }
    else if(a=='*' || a=='/' || a=='%' )
    {
        return 2;
    }
    else if(a=='+' || a=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void postfix(string s)
{ 
     int i;
    string a = "";
    i = 0;
    while (s[i] != '\0')
    {
        if (top == -1 && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^'))
        {
            push(s[i]);
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        }
        else if (top != -1 && (stack[top] == '(' || stack[top] == '[' || stack[top] == '{') && precedence(s[i]) > 0)
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            
            while (top != -1 && stack[top] != '(' && stack[top] != '[' && stack[top] != '{')
            {
                a = a + pop();
            }
            if (top != -1)
            {
                pop();
            }
        }
        else if (top != -1 && precedence(stack[top]) < precedence(s[i]))
        {
            push(s[i]);
        }
        else if (top != -1 && precedence(s[i]) > 0 && precedence(stack[top]) >= precedence(s[i]))
        {
            if (s[i] == '^' && stack[top] == '^')
            {
                push(s[i]);
            }
            else
            {
                while (top != -1 && precedence(stack[top]) >= precedence(s[i]))
                {
                    a = a + pop();
                }
                push(s[i]);
            }
        }
        else
        {
            a = a + s[i];
        }
        i++;
    }
    while (top != -1)
    {
        a = a + pop();
    }
    cout << "\nPostfix Expression is\n";
    cout << a;  
}
int main()
{
    string s1;
    cout<<"\nEnter one Infix expression: ";
    cin>>s1;
    postfix(s1); 
    return 0;
}