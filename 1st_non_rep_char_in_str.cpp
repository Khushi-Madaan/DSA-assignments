/*Write a program to find first non-repeating character in a string using Queue. 
Sample I/P: a a b c Sample O/P: a -1 b b */
#include<iostream>
#include<string>
using namespace std;
# define size 10
char queue[size];
int front=-1,rear=-1;
class Queue
{
public:
void enqueue(int n)
{
    if(rear==(size-1))
    {
        cout<<"\nOverflow State\n";
    }
    else if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        queue[rear]=n;
    }
    else
    {
        rear++;
        queue[rear]=n;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"\nUnderflow State\n";
    }
    else if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else
    {
        front++;
    }
}
void non_rep(string s)
{
    int i=0;
    int freq[26] = {0};
    while(s[i]!='\0')
    {
        freq[s[i] - 'a']++;
        enqueue(s[i]);
        while (front !=-1 && freq[queue[front] - 'a'] > 1)
        {
            dequeue();
        }
        if (front==-1 )
        {
            cout << "-1 ";
        }
        else
        {   
            cout << queue[front] << " ";
        }
        i++;
    }
}
};
int main()
{
    Queue q;
    string input;
    cout<<"\nEnter one string: ";
    cin>>input;
    q.non_rep(input);
    return 0;
}
