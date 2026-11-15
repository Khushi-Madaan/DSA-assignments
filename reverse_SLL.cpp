/*Write a program to reverse a linked list.
Input: 1 -> 2 -> 3 -> 4 -> NULL
Output: 4 -> 3 -> 2 -> 1 -> NULL*/
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
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    cout << "Reversed List: ";
    while (head != NULL)
    {
        if(head->next==NULL)
        {
        	cout << head->data	;
		}
		else
		{
			cout << head->data << " -> ";	
		}
        head = head->next;
    }
    return 0;
}

