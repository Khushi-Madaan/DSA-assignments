/*Write a program interleave the first half of the queue with second half. 
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9 */
#include<iostream>
using namespace std;
# define size 6
int queue[size];
int front=-1,rear=-1;
void enqueue(int n)
{
    if(rear==(size-1))
    {
        cout<<"\nOverflow State\n";
    }
    else if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        queue[rear]=n;
    }
    else
    {
        rear++;
        queue[rear]=n;
    }
}
void dequeue()
{
    if(front==-1)
    {
        cout<<"\nUnderflow State\n";
    }
    else if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else
    {
        front++;
    }
}
void traverse()
{
    if(front==-1)
    {
        cout<<"\nQueue is empty\n";
    }
    else
    {
        cout<<"\nQueue is:\n";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
    }
}
void rearrange()
{
int a[size];
int i,j=0;
int n=size/2;
for(i=front;i<size/2;i++)
{
    a[j]=queue[i];
    a[j+1]=queue[n];
    j=j+2;
    n++;
}
while(front!=-1)
{
    dequeue();
}
for(i=0;i<size;i++)
{
    enqueue(a[i]);
}
traverse();
}
int main()
{
    int i,e;
    for(i=0;i<size;i++)
    {
        cout<<"\nEnter queue elements : ";
        cin>>e;
        enqueue(e);
    }
    traverse();
    cout<<"\nQueue after rearrangement\n";
    rearrange();
    return 0;
}