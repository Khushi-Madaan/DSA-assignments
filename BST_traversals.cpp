/*Give me humanied source code in cpp for this assignment along with 
question. The source code should be as simple as possible so that it
looks like i have completed my assignment by myself.*/
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
void preorder(Node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node *root=NULL;
    cout<<"Create Binary Tree\n";
    root=createTree();
    cout<<"\nPreorder: ";
    preorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    return 0;
}

