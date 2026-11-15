/*Write a program for a Binary Search Tree (BST) having functions for:
(a) Insert an element (no duplicates are allowed).
(b) Delete an existing element.
(c) Find the maximum depth of BST.
(d) Find the minimum depth of BST.*/
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
    else
        cout<<"Duplicate value not allowed\n";
    return root;
}
Node* findMin(Node *root)
{
    while(root!=NULL && root->left!=NULL)
        root=root->left;
    return root;
}
Node* deleteNode(Node *root,int key)
{
    if(root==NULL)
        return NULL;
    if(key<root->data)
        root->left=deleteNode(root->left,key);
    else if(key>root->data)
        root->right=deleteNode(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        Node *temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
int maxDepth(Node *root)
{
    if(root==NULL)
        return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return 1+(left>right?left:right);
}
int minDepth(Node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL)
        return 1+minDepth(root->right);
    if(root->right==NULL)
        return 1+minDepth(root->left);
    int left=minDepth(root->left);
    int right=minDepth(root->right);
    return 1+(left<right?left:right);
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node *root=NULL;
    int choice,n;
    do
    {
        cout<<"\n1. Insert";
        cout<<"\n2. Delete";
        cout<<"\n3. Maximum Depth";
        cout<<"\n4. Minimum Depth";
        cout<<"\n5. Display";
        cout<<"\n6. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value: ";
                cin>>n;
                root=insert(root,n);
                break;
            case 2:
                cout<<"Enter value to delete: ";
                cin>>n;
                if(root==NULL)
                    cout<<"Tree is empty";
                else
                    root=deleteNode(root,n);
                break;
            case 3:
                cout<<"Maximum depth: "<<maxDepth(root);
                break;
            case 4:
                cout<<"Minimum depth: "<<minDepth(root);
                break;
            case 5:
                cout<<"BST: ";
                inorder(root);
                break;
            case 6:
                cout<<"Program ended";
                break;
            default:
                cout<<"Invalid choice";
        }
    }while(choice!=6);
    return 0;
}

