/**
->Create BST from input elements
->Do in-order traversal to get the sorted output.
*/

#include<iostream>

using namespace std;

int k ;

struct node{
    int data;
    node* left , *right;
};

node* Insert(int val , node *root)
{
    if(root == NULL){
        node* new_node = new node;
        new_node -> data = val;
        new_node -> left = new_node -> right = NULL;
        return new_node;
    }
    if(root -> data < val)
        root -> right = Insert(val , root -> right);
    else if(root -> data > val)
        root -> left = Insert(val , root -> left);
    return root;
}

void inorder(int arr[] , node* root )
{
    if(root == NULL)
        return;
    inorder(arr,root -> left);
    arr[k++] = root -> data;
    inorder(arr,root -> right);
}

void treeSort(int arr[] , int n)
{
    node* root = NULL;
    root = Insert(arr[0], root);

    for(int i=1;i<n;i++)
        root = Insert(arr[i],root);

    inorder(arr , root);
}

int main()
{
    int arr[] = {5, 4, 7, 2, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    treeSort(arr, n);
        for (int i=0; i<n; i++)
       cout << arr[i] << " ";

    return 0;
}
