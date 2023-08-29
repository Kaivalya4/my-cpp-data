#include<iostream>
#include<unordered_map>

using namespace std;

struct node{
    int data;
    struct node *left , *right;
};

node* newnode(int val)
{
    node* new_node = new node;
    new_node -> data = val;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

void inordertraversal(node* head)
{
    if(head == NULL)
        return ;
    inordertraversal(head -> left);
    cout << head -> data << " ";
    inordertraversal(head -> right);
}

node* solve(int in[] , int level[] , int start , int ends , int n)
{
    if(n<=0)
        return NULL;

    node* head = newnode(level[0]);
    int ind = -1;

    unordered_map<int ,int> umap;
    for(int i=start ; i<=ends ; i++)
    {
        if(in[i] == level[0]){
            ind = i ;
             break;
        }
    }

    //store all the value of left subtree in map
    for(int i=start ; i<ind ; i++)
        umap[in[i]] = 1;

        // Separate level order traversals
    // of left and right subtrees.
    int lsubtree[umap.size()]; //[index - start]
    int rsubtree[ends - start - umap.size()]; //[ends - index]
    int l=0 , r = 0;
    for(int i=1 ; i<n ; i++) //since the first value of levelorder is already processed we start from the next value
    {
        //map contains only mapping of left subtree
        if(umap[level[i]] == 1)
        {
            lsubtree[l++] = level[i];
        }
        else
            rsubtree[r++] = level[i];
    }

    // Recursively build left and right
    // subtrees and return root.
    head -> left = solve(in , lsubtree , start , ind - 1 , ind - start);
    head -> right = solve(in , rsubtree , ind+1 , ends , ends - ind);

    return head;
}

int main()
{
    int in[] = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = 7;
    node* head = solve(in, level , 0 , n-1 , n); //(in , level , startindex , endindex , size)
    inordertraversal(head); //we can easily verify using inorder traversal since we already have inorder array
    //available , if we have made the tree correctly then inorder array should match our inorder traversal
    return 0;
}
