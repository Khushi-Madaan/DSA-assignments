/*Implement priority queues using heaps.*/

#include<iostream>
using namespace std;
class PriorityQueue
{
    int a[100];
    int size;
public:
    PriorityQueue()
    {
        size=0;
    }
    void insert(int n)
    {
        if(size==100)
        {
            cout<<"Queue is full\n";
            return;
        }
        int i=size;
        a[size]=n;
        size++;
        while(i>0 && a[(i-1)/2]<a[i])
        {
            swap(a[i],a[(i-1)/2]);
            i=(i-1)/2;
        }
        cout<<"Element inserted\n";
    }
    void deleteMax()
    {
        if(size==0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        cout<<"Deleted element: "<<a[0]<<endl;
        a[0]=a[size-1];
        size--;
        int i=0;
        while(2*i+1<size)
        {
            int largest=2*i+1;
            if(2*i+2<size && a[2*i+2]>a[largest])
                largest=2*i+2;
            if(a[i]>=a[largest])
                break;
            swap(a[i],a[largest]);
            i=largest;
        }
    }
    void peek()
    {
        if(size==0)
            cout<<"Queue is empty\n";
        else
            cout<<"Highest priority element: "<<a[0]<<endl;
    }
    void display()
    {
        if(size==0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        cout<<"Priority Queue: ";
        for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    PriorityQueue q;
    int choice,n;
    do
    {
        cout<<"\n1. Insert";
        cout<<"\n2. Delete";
        cout<<"\n3. Peek";
        cout<<"\n4. Display";
        cout<<"\n5. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value: ";
                cin>>n;
                q.insert(n);
                break;
            case 2:
                q.deleteMax();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout<<"Program ended";
                break;
            default:
                cout<<"Invalid choice";
        }
    }while(choice!=5);
    return 0;
}

