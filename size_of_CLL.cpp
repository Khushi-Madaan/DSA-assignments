/*Program to Find the Size of a Circular Linked List (CLL)*/

#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void insert(int n)
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
}
int size()
{
    if(head == NULL)
        return 0;
    int count = 0;
    Node *p = head;
    do
    {
        count++;
        p = p->next;
    }while(p != head);
    return count;
}
void display()
{
    if(head == NULL)
        return;
    Node *p = head;
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    }while(p != head);
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
    cout<<"Circular Linked List: ";
    display();
    cout<<"\nSize of Circular Linked List: "<<size();
    return 0;
}

