/*Develop a menu-driven program for the following operations on a 
Circular Linked List.
(a) Insertion anywhere in the linked list (as a first node, as a 
last node, and after/before a specific node).
(b) Deletion of a specific node. The node to be deleted may appear 
as a head node, last node or a node in between.
(c) Search for a node.*/
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void insertFirst(int n)
{
    Node *temp = new Node;
    temp->data = n;
    if(head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Node *p = head;
        while(p->next != head)
            p = p->next;
        temp->next = head;
        p->next = temp;
        head = temp;
    }
    cout<<"Node inserted\n";
}
void insertLast(int n)
{
    Node *temp = new Node;
    temp->data = n;
    if(head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Node *p = head;
        while(p->next != head)
            p = p->next;
        p->next = temp;
        temp->next = head;
    }
    cout<<"Node inserted\n";
}
void insertAfter(int key, int n)
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    Node *p = head;
    do
    {
        if(p->data == key)
            break;
        p = p->next;
    }while(p != head);
    if(p->data != key)
    {
        cout<<"Node not found\n";
        return;
    }
    Node *temp = new Node;
    temp->data = n;
    temp->next = p->next;
    p->next = temp;
    cout<<"Node inserted\n";
}
void insertBefore(int key, int n)
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    if(head->data == key)
    {
        insertFirst(n);
        return;
    }
    Node *prev = head;
    Node *p = head->next;
    while(p != head && p->data != key)
    {
        prev = p;
        p = p->next;
    }
    if(p == head)
    {
        cout<<"Node not found\n";
        return;
    }
    Node *temp = new Node;
    temp->data = n;
    temp->next = p;
    prev->next = temp;
    cout<<"Node inserted\n";
}
void deleteNode(int key)
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    Node *p = head;
    if(head->data == key)
    {
        if(head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *last = head;
            while(last->next != head)
                last = last->next;
            Node *temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }
        cout<<"Node deleted\n";
        return;
    }
    Node *prev = head;
    p = head->next;
    while(p != head && p->data != key)
    {
        prev = p;
        p = p->next;
    }
    if(p == head)
    {
        cout<<"Node not found\n";
        return;
    }
    prev->next = p->next;
    delete p;
    cout<<"Node deleted\n";
}
void searchNode(int key)
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    Node *p = head;
    int pos = 1;
    do
    {
        if(p->data == key)
        {
            cout<<"Node found at position "<<pos<<endl;
            return;
        }
        p = p->next;
        pos++;
    }while(p != head);
    cout<<"Node not found\n";
}
void display()
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    Node *p = head;
    cout<<"Circular Linked List: ";
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    }while(p != head);
    cout<<endl;
}
int main()
{
    int choice, n, key;
    do
    {
        cout<<"\n1. Insert at First";
        cout<<"\n2. Insert at Last";
        cout<<"\n3. Insert After a Node";
        cout<<"\n4. Insert Before a Node";
        cout<<"\n5. Delete a Node";
        cout<<"\n6. Search a Node";
        cout<<"\n7. Display";
        cout<<"\n8. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value: ";
                cin>>n;
                insertFirst(n);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>n;
                insertLast(n);
                break;
            case 3:
                cout<<"Enter the node value: ";
                cin>>key;
                cout<<"Enter new value: ";
                cin>>n;
                insertAfter(key,n);
                break;
            case 4:
                cout<<"Enter the node value: ";
                cin>>key;
                cout<<"Enter new value: ";
                cin>>n;
                insertBefore(key,n);
                break;
            case 5:
                cout<<"Enter value to delete: ";
                cin>>key;
                deleteNode(key);
                break;
            case 6:
                cout<<"Enter value to search: ";
                cin>>key;
                searchNode(key);
                break;
            case 7:
                display();
                break;
            case 8:
                cout<<"Program ended\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    }while(choice != 8);
    return 0;
}

