/*Design the logic to remove the duplicate elements from an Array
and after the deletion the array should contain the unique elements*/
#include<iostream>
using namespace std;
int main()
{
    int a[]={1,5,2,1,7,5};
    int i,n=6;
    cout<<"ARRAY IS:"<<endl;
    for(i=0;i<n;i++)
    {
        if(i==(n-1))
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
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                for(int k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];
                }
                a[n-1]=0;
                n--;
                j--;
            }
        }
    }
    cout<<"\nARRAY AFTER REMOVING DUPLICATES"<<endl;
    for(i=0;i<n;i++)
    {
        if(i==(n-1))
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