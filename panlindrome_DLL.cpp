/*Write a program to check if a doubly linked list of characters is 
palindrome or not.*/

#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node *prev;
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    char ch;
    cout << "Enter number of characters: ";
    cin >> n;
    cout << "Enter characters: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        Node *temp = new Node;
        temp->data = ch;
        temp->next = NULL;
        temp->prev = tail;
        if (head == NULL)
            head = temp;
        else
            tail->next = temp;
        tail = temp;
    }
    Node *p = head;
    Node *q = tail;
    bool palindrome = true;
    while (p != NULL && q != NULL)
    {
        if (p->data != q->data)
        {
            palindrome = false;
            break;
        }
        if (p == q || p->next == q)
            break;
        p = p->next;
        q = q->prev;
    }
    if (palindrome)
        cout << "True - Palindrome";
    else
        cout << "False - Not Palindrome";
    return 0;
}

