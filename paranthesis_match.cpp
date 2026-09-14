//Write a program that checks if an expression has balanced parentheses. 
#include<iostream>
#include<string>
#define size 50
using namespace std;
char stack[size];
int top=-1,f=0;
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
void pop()
{
    if(top==-1)
    {
        cout<<"\nStack is empty";
    }
    else
    {
        top--;
    }
}
char peek() 
{
    return stack[top];
}
void paranthesis(string s)
{
   int i=0;
   while(s[i]!='\0')
   {
    if(s[i]=='(' || s[i]=='[' || s[i]=='{')
    {
        push(s[i]);
    }
    else if(s[i]==')' || s[i]==']' || s[i]=='}')
    {
        char e=peek();
        if(e=='(' && s[i]==')' || e=='{' && s[i]=='}' || e=='[' && s[i]==']')
        {
            f=1;
            pop();
        }
        else
        {
            f=0;
        }
   }
   i++;
   }
    if(f==0 || top!=-1)
    {
        cout<<"\nParanthesis are not matched";
    }
    else
    {
        cout<<"\nParanthesis are matched";
    }
}
int main()
{
    string s;
    cout<<"\nEnter paranthesis: ";
    cin>>s;
    paranthesis(s);
    return 0;
}