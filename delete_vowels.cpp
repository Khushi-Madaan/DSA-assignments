//W.A.P. to delete all the vowels from the string.
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    int c=0;
    cout<<"\nEnter a string: ";
    getline(cin,s1);
    int i=0;
    while(s1[i]!='\0')
    {
        c=c+1;
        i++;
    }
    cout<<"\nString is: "<<s1;
    for(int i=0;i<c;i++)
    {
        if(s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='o' || s1[i]=='u')
        {
            for(int j=i;j<c-1;j++)
            {
                s1[j]=s1[j+1];
            }
            c--;
            i--;
        }
    }
    s1.resize(c);
    cout<<"\nString after removing all the vowels is: "<<s1;
    return 0;
}
