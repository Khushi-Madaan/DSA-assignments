/*Implement the following functions for Binary Search Trees:
(a) Search a given item (Recursive and Non-Recursive)
(b) Find the maximum element of the BST.
(c) Find the minimum element of the BST.
(d) Find the In-order successor of a given node in the BST.
(e) Find the In-order predecessor of a given node in the BST.*/
#include<iostream>
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
Node* insert(Node *root,int n)
{
    if(root==NULL)
        return new Node(n);
    if(n<root->data)
        root->left=insert(root->left,n);
    else if(n>root->data)
        root->right=insert(root->right,n);
    return root;
}
bool recursiveSearch(Node *root,int key)
{
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    if(key<root->data)
        return recursiveSearch(root->left,key);
    return recursiveSearch(root->right,key);
}
bool iterativeSearch(Node *root,int key)
{
    while(root!=NULL)
    {
        if(root->data==key)
            return true;
        if(key<root->data)
            root=root->left;
        else
            root=root->right;
    }
    return false;
}
Node* minimum(Node *root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
Node* maximum(Node *root)
{
    if(root==NULL)
        return NULL;
    while(root->right!=NULL)
        root=root->right;
    return root;
}
Node* successor(Node *root,int key)
{
    Node *current=root,*ans=NULL;
    while(current!=NULL)
    {
        if(key<current->data)
        {
            ans=current;
            current=current->left;
        }
        else if(key>current->data)
            current=current->right;
        else
        {
            if(current->right!=NULL)
                ans=minimum(current->right);
            break;
        }
    }
    return ans;
}
Node* predecessor(Node *root,int key)
{
    Node *current=root,*ans=NULL;
    while(current!=NULL)
    {
        if(key>current->data)
        {
            ans=current;
            current=current->right;
        }
        else if(key<current->data)
            current=current->left;
        else
        {
            if(current->left!=NULL)
                ans=maximum(current->left);
            break;
        }
    }
    return ans;
}
int main()
{
    Node *root=NULL;
    int n,x,key,choice;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter values: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        root=insert(root,x);
    }
    do
    {
        cout<<"\n1. Recursive Search";
        cout<<"\n2. Non-Recursive Search";
        cout<<"\n3. Minimum Element";
        cout<<"\n4. Maximum Element";
        cout<<"\n5. Inorder Successor";
        cout<<"\n6. Inorder Predecessor";
        cout<<"\n7. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;
        if(choice>=1 && choice<=6)
        {
            if(choice==3)
            {
                Node *p=minimum(root);
                if(p!=NULL)
                    cout<<"Minimum: "<<p->data;
                else
                    cout<<"Tree is empty";
            }
            else if(choice==4)
            {
                Node *p=maximum(root);
                if(p!=NULL)
                    cout<<"Maximum: "<<p->data;
                else
                    cout<<"Tree is empty";
            }
            else
            {
                cout<<"Enter value: ";
                cin>>key;
                if(choice==1)
                    cout<<(recursiveSearch(root,key)?"Found":"Not Found");
                else if(choice==2)
                    cout<<(iterativeSearch(root,key)?"Found":"Not Found");
                else if(choice==5)
                {
                    Node *p=successor(root,key);
                    if(p!=NULL)
                        cout<<"Successor: "<<p->data;
                    else
                        cout<<"No successor found";
                }
                else if(choice==6)
                {
                    Node *p=predecessor(root,key);
                    if(p!=NULL)
                        cout<<"Predecessor: "<<p->data;
                    else
                        cout<<"No predecessor found";
                }
            }
        }
    }while(choice!=7);
    return 0;
}

