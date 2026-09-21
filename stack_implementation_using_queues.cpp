//Write a program to implement a stack using (a) Two Queues. 
#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q1, q2;
public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            cout << "Popped: " << q1.front() << endl;
            q1.pop();
        }
    }
    void peek()
    {
        if (q1.empty())
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << q1.front() << endl;
    }
    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        queue<int> temp = q1;
        cout << "Stack: ";
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    return 0;
}
