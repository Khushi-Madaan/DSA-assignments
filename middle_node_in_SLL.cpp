/*Write a program to find the middle of a linked list.
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 3 */

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
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != NULL)
        cout << "Middle element: " << slow->data;
    else
        cout << "List is empty";
    return 0;
}

