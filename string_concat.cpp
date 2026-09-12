//W.A.P. to concatenate one string to another string
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    cout<<"\nEnter first string: ";
    getline(cin,s1);
    cout<<"\nEnter second string: ";
    getline(cin,s2);
    int i=0,j=0;
    while(s1[i]!='\0')
    {
        i++;
    }
    s1.resize(i+1+s2.length());
    s1[i]=' ';
    i++;
    while(s2[j]!='\0')
    {
        s1[i]=s2[j];
        i++;
        j++;
    }
    cout<<"\nString after concatenation is: "<<s1;
    return 0;
}
