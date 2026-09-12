//W.A.P. to convert a character from uppercase to lowercase.
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char c;
    cout<<"\nEnter one alphabetical character: ";
    cin>>c;
    if(c>='A' & c<='Z')
    {
        c=c+32;
    }
    cout<<"\nLowercase Character is: "<<c;
    return 0;
}
