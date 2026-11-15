/*Develop a menu-driven program to perform the following operations on a Singly Linked List:
1. Insertion at the beginning.
2. Insertion at the end.
3. Insertion before or after a node having a specific value.
4. Deletion from the beginning.
5. Deletion from the end.
6. Deletion of a specific node.
7. Search for a node and display its position from the head.
8. Display all node values.*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void insertBeginning(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;
}
void insertEnd(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
}
void insertBetween(int n, int value, int choice)
{
    Node *p = head;
    while (p != NULL && p->data != value)
        p = p->next;
    if (p == NULL)
    {
        cout << "Value not found\n";
        return;
    }
    Node *temp = new Node;
    temp->data = n;
    if (choice == 1)
    {
        temp->next = p;
        if (p == head)
            head = temp;
        else
        {
            Node *q = head;
            while (q->next != p)
                q = q->next;
            q->next = temp;
        }
    }
    else
    {
        temp->next = p->next;
        p->next = temp;
    }
}
void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *p = head;
    while (p->next->next != NULL)
        p = p->next;
    delete p->next;
    p->next = NULL;
}
void deleteSpecific(int n)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->data == n)
    {
        deleteBeginning();
        return;
    }
    Node *p = head;
    while (p->next != NULL && p->next->data != n)
        p = p->next;
    if (p->next == NULL)
        cout << "Node not found\n";
    else
    {
        Node *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}
void searchNode(int n)
{
    Node *p = head;
    int pos = 1;
    while (p != NULL)
    {
        if (p->data == n)
        {
            cout << "Node found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Node not found\n";
}
void display()
{
    Node *p = head;
    if (p == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}
int main()
{
    int choice, n, value, side;
    do
    {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert Before/After a Node";
        cout << "\n4. Delete from Beginning";
        cout << "\n5. Delete from End";
        cout << "\n6. Delete Specific Node";
        cout << "\n7. Search Node";
        cout << "\n8. Display";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> n;
            insertBeginning(n);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> n;
            insertEnd(n);
            break;
        case 3:
            cout << "Enter new value: ";
            cin >> n;
            cout << "Enter existing node value: ";
            cin >> value;
            cout << "1. Before  2. After: ";
            cin >> side;
            insertBetween(n, value, side);
            break;
        case 4:
            deleteBeginning();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> n;
            deleteSpecific(n);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> n;
            searchNode(n);
            break;
        case 8:
            display();
            break;
        case 9:
            cout << "Program ended";
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice != 9);
    return 0;
}


