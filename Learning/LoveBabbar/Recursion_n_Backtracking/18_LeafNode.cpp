//print all leaf nodes of the tree from left to right
//time = O(n)

#include<iostream>

using namespace std;

struct tree{
    int data;
    struct tree* left  , *right;
};
tree* root = NULL;

void solve(tree* node)
{
    if(node == NULL)
        return ;
    if(node -> left == NULL && node -> right == NULL)
    {
        cout << node -> data << " ";
        return ;
    }
    solve(node -> left);
    solve(node -> right);
}

tree* newNode(int data)
{
    tree* new_node = new tree;
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

int main()
{
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    solve(root);
}
