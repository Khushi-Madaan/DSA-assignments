/*Develop a menu-driven program for the following operations on a 
Doubly Linked List.
(a) Insertion anywhere in the linked list (as a first node, as a last
node, and after/before a specific node).
(b) Deletion of a specific node. The node to be deleted may appear as
a head node, last node or a node in between.
(c) Search for a node.*/
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;
void insertFirst(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->prev = NULL;
    temp->next = head;
    if(head != NULL)
        head->prev = temp;
    head = temp;
    cout<<"Node inserted\n";
}
void insertLast(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        Node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
        temp->prev = p;
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
    while(p != NULL && p->data != key)
        p = p->next;
    if(p == NULL)
    {
        cout<<"Node not found\n";
        return;
    }
    Node *temp = new Node;
    temp->data = n;
    temp->next = p->next;
    temp->prev = p;
    if(p->next != NULL)
        p->next->prev = temp;
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
    Node *p = head;
    while(p != NULL && p->data != key)
        p = p->next;
    if(p == NULL)
    {
        cout<<"Node not found\n";
        return;
    }
    Node *temp = new Node;
    temp->data = n;
    temp->next = p;
    temp->prev = p->prev;
    if(p->prev != NULL)
        p->prev->next = temp;
    else
        head = temp;
    p->prev = temp;
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
    while(p != NULL && p->data != key)
        p = p->next;
    if(p == NULL)
    {
        cout<<"Node not found\n";
        return;
    }
    if(p->prev != NULL)
        p->prev->next = p->next;
    else
        head = p->next;
    if(p->next != NULL)
        p->next->prev = p->prev;
    delete p;
    cout<<"Node deleted\n";
}
void searchNode(int key)
{
    Node *p = head;
    int pos = 1;
    while(p != NULL)
    {
        if(p->data == key)
        {
            cout<<"Node found at position "<<pos<<endl;
            return;
        }
        p = p->next;
        pos++;
    }
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
    cout<<"Doubly Linked List: ";
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
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

