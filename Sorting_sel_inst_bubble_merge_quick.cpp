/*mplement the following sorting techniques:
(a) Selection Sort
(b) Insertion Sort
(c) Bubble Sort
(d) Merge Sort
(e) Quick Sort */
#include<iostream>
using namespace std;
void selectionSort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[i],a[min]);
    }
}

void insertionSort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void bubbleSort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

void merge(int a[], int low, int mid, int high)
{
    int temp[100], i=low, j=mid+1, k=0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=high)
        temp[k++] = a[j++];
    for(i=low, k=0; i<=high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low-1;
    for(int j=low; j<high; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

void display(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[100], b[100], n, choice;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>a[i];

    do
    {
        cout<<"\n1. Selection Sort";
        cout<<"\n2. Insertion Sort";
        cout<<"\n3. Bubble Sort";
        cout<<"\n4. Merge Sort";
        cout<<"\n5. Quick Sort";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        for(int i=0; i<n; i++)
            b[i] = a[i];

        switch(choice)
        {
            case 1:
                selectionSort(b,n);
                break;
            case 2:
                insertionSort(b,n);
                break;
            case 3:
                bubbleSort(b,n);
                break;
            case 4:
                mergeSort(b,0,n-1);
                break;
            case 5:
                quickSort(b,0,n-1);
                break;
            case 6:
                cout<<"Program ended";
                break;
            default:
                cout<<"Invalid choice";
                continue;
        }
        if(choice>=1 && choice<=5)
        {
            cout<<"Sorted array: ";
            display(b,n);
        }
    }while(choice!=6);
    return 0;
}

