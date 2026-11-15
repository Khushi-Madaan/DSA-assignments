/*Write a program to display all the node values in a circular linked
list, repeating the value of the head node at the end too.
Input: 20 -> 100 -> 40 -> 80 -> 60
Output: 20 100 40 80 60 20 */ 
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
    int n, value;
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
    if (head != NULL)
        tail->next = head;
    cout << "Circular Linked List: ";
    if (head != NULL)
    {
        Node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << head->data;
    }
    return 0;
}


