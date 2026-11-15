/*Write a program to check if a linked list is a Circular Linked List
 or not.
Example: 2 -> 4 -> 6 -> 7 -> 5
Output: True if the last node points back to the first node.*/

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n, value, pos;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    cout << "Enter position to connect last node (0 for no loop): ";
    cin >> pos;
    if (pos > 0 && pos <= n)
    {
        Node *p = head;
        for (int i = 1; i < pos; i++)
            p = p->next;
        tail->next = p;
    }
    Node *slow = head;
    Node *fast = head;
    bool circular = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            circular = true;
            break;
        }
    }
    if (circular)
        cout << "True - Circular Linked List";
    else
        cout << "False - Not Circular Linked List";
    return 0;
}

