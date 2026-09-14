/*Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion 
if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
of inversions in an array. */
#include<iostream>
using namespace std;
int main()
{
    int n,i,j,inv=0;
    cout<<"\nEnter Size of array: ";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter array elements: ";
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                inv+=1;
            }
        }
    }
    cout<<"\nNo. of Inversions in an array are: "<<inv;
}