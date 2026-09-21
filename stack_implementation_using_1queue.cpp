//Write a program to implement a stack using (a) Two Queue
#include<iostream>
using namespace std;
# define size 100
int queue[size];
int front=-1,rear=-1;
class Queue
{
public:
bool isFull()
{
    return (rear==(size-1));
}
bool isEmpty()
{
    return (rear==-1 && front==-1);
}
void push(int n)
{
    if(isFull())
    {
        cout<<"\nOverflow State\n";
    }
    else if(isEmpty())
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
    stack();
}
void stack()
{
    if(rear>0)
    {
        for(int i=front;i<rear;i++)
        {
           int temp=queue[front];
          for(int j=front;j<rear;j++)
          {
            queue[j]=queue[j+1];
          }
          queue[rear]=temp;
        }
    }
}
void pop()
{
    if(isEmpty())
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
void peek()
{
    if(isEmpty())
    {
        cout<<"\nStack is empty\n";
    }
    else
    {
        cout<<"\nToppest element is: "<<queue[front];
    }
}
void display()
{
    if(isEmpty())
    {
        cout<<"\nStack is empty\n";
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
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.peek();
    return 0;
}
