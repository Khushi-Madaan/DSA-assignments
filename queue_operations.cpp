/*Develop a menu driven program demonstrating the following operations on simple Queues: enqueue(), 
dequeue(), isEmpty(), isFull(), display(), and peek(). */
#include<iostream>
using namespace std;
# define size 10
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
void enqueue(int n)
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
}
void dequeue()
{
    if(isEmpty())
    {
        cout<<"\nUnderflow State\n";
    }
    else if(front==rear)
    {
        cout<<"\nDeleted element is "<<queue[front];
        rear=-1;
        front=-1;
    }
    else
    {
        cout<<"\nDeleted element is "<<queue[front];
        front++;
    }
}
int peek()
{
    if(isEmpty())
    {
        cout<<"\nQueue is empty\n";
        return 0;
    }
    else
    {
        return queue[front];
    }
}
void display()
{
    if(isEmpty())
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
};
int main()
{
    Queue q;
    int choice, value;
    do
    {
        cout << "\n===== SIMPLE QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is not Empty." << endl;
            break;
        case 4:
            if (q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is not Full." << endl;
            break;
        case 5:
            q.display();
            break;
        case 6:
            cout<< "Front element is : " <<q.peek()<< endl;
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
