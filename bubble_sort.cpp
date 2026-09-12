/* Code the bubble sort with the following elements:
64,34,25,12,22,11,90*/
#include<iostream>
using namespace std;
int main()
{
int a[]={64,34,25,12,22,11,90};
int n=(sizeof(a))/(sizeof(a[0]));
int i,j;
cout<<"Array is:\n";
for(i=0;i<n;i++)
{
    if(i==n-1)
    {
        cout<<a[i];
    }
    else
    {
        cout<<a[i]<<",";
    }
}
for(i=0;i<n;i++)
{
    for(j=0;j<n-i;j++)
    {
        if(a[j]>a[j+1])
        {
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}
cout<<"\nArray After bubble sort:\n";
for(i=0;i<n;i++)
{
    if(i==n-1)
    {
        cout<<a[i];
    }
    else
    {
        cout<<a[i]<<",";
    }
}
return 0;
}