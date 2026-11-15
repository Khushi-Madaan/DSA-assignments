/*We know that selection sort takes the minimum element on every pass
and places it at its correct position. The idea is to also take the 
maximum element on every pass and place it at its correct position. 
So, in every pass, we keep track of both maximum and minimum, and the
array becomes sorted from both ends. Implement this logic.*/
#include<iostream>
using namespace std;
int main()
{
    int a[100], n;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>a[i];
    int start=0, end=n-1;
    while(start<end)
    {
        int min=start, max=start;
        for(int i=start; i<=end; i++)
        {
            if(a[i]<a[min])
                min=i;
            if(a[i]>a[max])
                max=i;
        }
        swap(a[start],a[min]);

        if(max==start)
            max=min;
        swap(a[end],a[max]);
        start++;
        end--;
    }
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

