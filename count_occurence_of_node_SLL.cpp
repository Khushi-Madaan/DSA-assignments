/*Write a program to count the number of occurrences of a given key 
in a singly linked list and then delete all the occurrences.
Input: Linked List: 1 -> 2 -> 1 -> 2 -> 1 -> 3 -> 1, Key: 1
Output: Count: 4, Updated Linked List: 2 -> 2 -> 3  */

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
    int n, value, key, count = 0;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter list values: ";
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
    cout << "Enter key: ";
    cin >> key;
    Node *p = head;
    Node *prev = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            count++;
            Node *temp = p;
            if (prev == NULL)
                head = p->next;
            else
                prev->next = p->next;
            p = p->next;
            delete temp;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    p = head;
    while (p != NULL)
    {
        if(p->next==NULL)
        {
        	cout << p->data	;
		}
		else
		{
			cout << p->data << " -> ";	
		}
        p = p->next;
    }
    return 0;
}

