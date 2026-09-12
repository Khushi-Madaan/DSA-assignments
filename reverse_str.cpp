//W.A.P. to reverse a string.
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    int temp,c=0;
    cout<<"\nEnter a string: ";
    getline(cin,s1);
    int i=0;
    while(s1[i]!='\0')
    {
        c=c+1;
        i++;
    }
    cout<<"\nString is: "<<s1;
    int j=c-1;
    for(int i=0;i<c/2;i++)
    {
        temp=s1[i];
        s1[i]=s1[j];
        s1[j]=temp;
        j--;
    }
    cout<<"\nReverse of String is: "<<s1;
}
