/*
We will do -
1.Inorder traversal(Iterative : for practise)
2.Search a value
3.Insert a node
*/

#include<iostream>
#include<stack>

using namespace std;

struct node{
    int data;
    node* left , *right;
};

void inorder(node* root)
{
    stack<node*> s;
    node* curr = root;
    while(curr || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr = curr -> left;
        }
        if(!s.empty()){
        curr = s.top();
        s.pop();
        cout << curr -> data << " ";
        curr = curr -> right;
        }
    }
}

node* inserts(node* root , int val)
{
    if(root == NULL)
    {
        node* new_node = new node;
        new_node -> data = val;
        new_node -> left = NULL;
        new_node -> right = NULL;
        root = new_node;
        return root;
    }
    if(val < (root -> data))
        root -> left = inserts(root -> left , val);
    else
        root -> right = inserts(root -> right , val);
    return root;
}

bool searchs(node* root , int val)
{
    if(root == NULL)
        return false;
    if(root -> data == val)
        return true;
    return searchs(root -> left ,val) || searchs(root -> right ,val) ;
}

int main()
{
    node* root = NULL;
    root = inserts(root , 8);
    root = inserts(root , 3);
    root = inserts(root , 10);
    root = inserts(root , 1);
    root = inserts(root , 6);
    root = inserts(root , 14);
    root = inserts(root , 4);
    root = inserts(root , 7);
    root = inserts(root , 13);

    cout << "Inorder Traversal of newly created bst : ";
    inorder(root);
    cout << endl;

    int val = 6;
    if(searchs(root , val))
        cout << "value is found !!!" ;
    else
        cout << "vlaue is not found !!!";
    return 0;
}
