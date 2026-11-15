/*Write a program to determine whether a given binary tree is a 
Binary Search Tree (BST) or not.*/

#include<iostream>
#include<climits>
using namespace std;
class Node
{
public:
    int data;
    Node *left,*right;
    Node(int n)
    {
        data=n;
        left=right=NULL;
    }
};
Node* createTree()
{
    int n;
    cout<<"Enter value (-1 for no node): ";
    cin>>n;
    if(n==-1)
        return NULL;
    Node *temp=new Node(n);
    cout<<"Enter left child of "<<n<<endl;
    temp->left=createTree();
    cout<<"Enter right child of "<<n<<endl;
    temp->right=createTree();
    return temp;
}
bool checkBST(Node *root,long long min,long long max)
{
    if(root==NULL)
        return true;
    if(root->data<=min || root->data>=max)
        return false;
    return checkBST(root->left,min,root->data) &&
           checkBST(root->right,root->data,max);
}
int main()
{
    Node *root=NULL;
    cout<<"Create Binary Tree\n";
    root=createTree();
    if(checkBST(root,LLONG_MIN,LLONG_MAX))
        cout<<"It is a BST";
    else
        cout<<"It is not a BST";
    return 0;
}

