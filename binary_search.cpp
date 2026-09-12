//Implement the binary search algorithm.
#include<iostream>
using namespace std;
int main()
{
    int i,j,size;
    cout<<"Enter the number of elements in an array: ";
    cin>>size;
    int a[size];
    for(i=0;i<size;i++)
    {
        cout<<"\nEnter array elements: ";
        cin>>a[i];
    }
    for(i=0;i<size;i++)         //sort an array
    {
        for(j=0;j<size-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int e;
    cout<<"\nEnter an element to be searched: ";
    cin>>e;
    int lb=0,ub=size-1;
    int mid,c=0;
    i=lb;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(e>a[mid])
        {
            lb=mid+1;
         }
        else if(e==a[mid])
        {
            cout<<"\nElement is found";
            c=1;
            break;
        }
        else
        {
            ub=mid-1;
        }
    }
    if(c==0)
    {
        cout<<"\nElement si not found";
    }  
    return 0; 
}   

    
       