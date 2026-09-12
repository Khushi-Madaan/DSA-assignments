//W.A.P. to sort the strings in alphabetical order.
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s[]={"Banana","Apple","Orange","Mango"};
    int i,j,n=4;
    string temp;
    cout<<"\nStrings in an Array are:\n";
    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            cout<<s[i];
        }
        else
        {
            cout<<s[i]<<",";
        }
        
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(s[i]>s[j])
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    cout<<"\nArray after sorting of Strings\n";
    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            cout<<s[i];
        }
        else
        {
            cout<<s[i]<<",";
        }
        
    }
    return 0;
}
