//Given a string, reverse it using stack.
#include<iostream>
#include<string>
#define size 50
using namespace std;
char stack[size];
int top=-1;
void push(char n)
{
    if(top==(size-1))
    {
        cout<<"\nSORRY! Stack is full";
    }
    else
    {
        top++;
        stack[top]=n;
    }
}
char pop()
{
    char e;
    if(top==-1)
    {
        cout<<"\nUnderflow";
    }
    else
    {
        e=stack[top];
        top--;
        return e;
    }
}
void reverse(string s)
{
   int i=0;
    while(s[i]!='\0')
    {
        push(s[i]);
        i++;
    }
    int j=top;
    for(i=0;i<=j;i++)
    {
        s[i]=pop();
    }
    cout<<"\nString after reversing it using stack is\n";
    i=0;
    while(s[i]!='\0')
    {
        cout<<s[i]<<" ";
        i++;
    }
}
int main()
{
    string s;
    cout<<"\nEnter one string: ";
    cin>>s;
    reverse(s);
    return 0;
}

