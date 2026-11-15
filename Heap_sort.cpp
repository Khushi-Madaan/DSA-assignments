/*Implement Heap Sort to arrange the elements in increasing and 
decreasing order.*/ 
#include<iostream>
using namespace std;
void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main()
{
    int a[100],n,choice;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"1. Increasing Order";
    cout<<"\n2. Decreasing Order";
    cout<<"\nEnter choice: ";
    cin>>choice;
    heapSort(a,n);
    if(choice==1)
    {
        cout<<"Increasing order: ";
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
    }
    else if(choice==2)
    {
        cout<<"Decreasing order: ";
        for(int i=n-1;i>=0;i--)
            cout<<a[i]<<" ";
    }
    else
        cout<<"Invalid choice";
    return 0;
}


