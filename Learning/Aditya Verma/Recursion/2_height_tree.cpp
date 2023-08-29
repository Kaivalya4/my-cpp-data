#include<iostream>

using namespace std;

class node 
{ 
    public:
    int data; 
    node* left; 
    node* right; 
}; 

node* newNode(int data) 
{ 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
     
    return(Node); 
} 

int large(int lh , int rh)
{
    if(lh>rh)
        return lh;
    else 
        return rh;
}

int height(node* root)
{
    if(root == NULL)
        return 0;
    int lh = height(root -> left);
    int rh = height(root -> right);

    return 1+large(lh , rh);
}

int main()
{
    node *root = newNode(1); 
 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);

    cout<< "height of tree is : " << height(root);
    return 0;
}