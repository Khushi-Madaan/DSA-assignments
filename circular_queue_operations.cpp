/*Develop a menu driven program demonstrating the following operations on Circular Queues: enqueue(),
dequeue(), isEmpty(), isFull(), display(), and peek().  */
#include<iostream>
using namespace std;
# define size 6
int queue[size];
int front=-1,rear=-1;
class Queue
{
    public:
    bool isFull()
    {
        return ((rear+1)%size==front);
    }
    bool isEmpty()
    {
        return (rear==-1 && front==-1);
    }
    void enqueue(int n)
    {
        if(isEmpty())
        {
            front=rear=0;
            queue[rear]=n;
        }
        else if(isFull())
        {
            cout<<"\nQueue is full\n";
        }
        else
        {
            rear=(rear+1)%size;
            queue[rear]=n;
        }
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"\nQueue is empty";
        }
        else if(front==rear)
        {
            cout<<"\nDeleted element is: "<<queue[front];
            front=rear=-1;
        }
        else
        {
            cout<<"\nDeleted element is: "<<queue[front];
            front=(front+1)%size;
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
        int i;
        cout<<"\nQueue is:\n";
        for(i=front;i!=rear;i=(i+1)%size)
        {
            cout<<queue[i]<<" ";
        }
        cout<<queue[i];
    }
};
int main()
{
    Queue q;
    int choice, value;
    do
    {
        cout << "\n===== Circular QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin>>choice;
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
            cout<< "Front element of Queue is: "<< q.peek() << endl;
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