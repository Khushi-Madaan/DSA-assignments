/*Program to Find the Size of a Doubly Linked List (DLL)*/

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
void insert(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
        head = temp;
    else
    {
        Node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
        temp->prev = p;
    }
}
int size()
{
    int count = 0;
    Node *p = head;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void display()
{
    Node *p = head;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main()
{
    int n, value;
    cout<<"Enter number of nodes: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter value: ";
        cin>>value;
        insert(value);
    }
    cout<<"Doubly Linked List: ";
    display();
    cout<<"\nSize of Doubly Linked List: "<<size();
    return 0;
}

