//W.A.P. to count the total number of distinct elements in an array of length n.
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"\nEnter length of array: ";
    cin>>n;
    int a[n],b[n];
    int i,j,size,c=0,flag;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter array elements: ";
        cin>>a[i];
    }
    b[0]=a[0];
    size=1;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<size;j++)
        {
            if(a[i]==b[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
           b[size]=a[i];
           size++;
        }
    }
    cout<<"\nArray is\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nNo. of distinct elements in an array is: "<<size;

}