/*Develop a menu driven program demonstrating the following operations on a Stack using array:
(i)push(),  (ii) pop(),  (iii) isEmpty(),  (iv) isFull(),  (v) display(), and  (vi) peek(). */
#include<iostream>
using namespace std;
#define size 100
int stack[size];
int top=-1;
class stack_oper
{
    public:
    bool isEmpty()
    {
        return top<0;
    }
    bool isFull()
    {
        return top>(size-1);
    }
    void push(int n)
    {
        if(isFull())
        {
            cout<<"\nStack Overflow! Cannot push\n";
        }
        else
        {
            top++;
            stack[top]=n;
            cout<<"\n"<<n<<" pushed into stack\n";
        }
    }
    int pop()
    {
        int x;
        if(isEmpty())
        {
            cout<<"\nStack Underflow! Cannot pop\n";
            return -1;
        }
        else
        {
        x=stack[top];
        top--;
        return x;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"\nStack is empty\n";
            return -1;
        }
        else
        {
            return stack[top];
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
            int i;
            cout<<"\nStack is:\n";
            for(i=top;i>=0;i--)
            {
                cout<<stack[i]<<" ";
            }
        }   
    }
};
int main() 
{
    stack_oper s;
    int choice, value;
    do {
        cout << "\n--- STACK OPERATIONS MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check isEmpty\n";
        cout << "4. Check isFull\n";
        cout << "5. Display Stack\n";
        cout << "6. Peek Top Element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if (value != -1) 
                {
                    cout<<"Popped element: " << value << "\n";
                }
                break;
            case 3:
                if (s.isEmpty()) 
                {
                    cout<< "Stack is empty.\n";
                } 
                else 
                {
                    cout<<"Stack is not empty.\n";
                }
                break;
            case 4:
                if (s.isFull()) 
                {
                    cout<<"Stack is full.\n";
                } else 
                {
                    cout<<"Stack is not full.\n";
                }
                break;
            case 5:
                s.display();
                break;
            case 6:
                value = s.peek();
                if (value != -1) 
                {
                    cout<<"Top element is: " << value << "\n";
                }
                break;
            case 7:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    } while (choice!=7);
    return 0;
}