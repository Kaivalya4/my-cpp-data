/*
-> Brute Force in O(n^2) : fix one element and find other element so that product becomes equal to k
-> Using map
*/
#include<iostream>
#include<unordered_map>

using namespace std;

struct node{
    int data;
    node* next;
};

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = new node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
bool check_pair_product(node* head ,int k)
{
    unordered_map<int  , int> umap;
    node* ptr = head;
    while(ptr != NULL)
    {
        umap[ptr -> data] ++;
        ptr = ptr -> next;
    }
    ptr = head;
    while(ptr != NULL)
    {
        int curr = ptr ->data;
        if(umap[k/curr] && k%curr == 0)
        {
            //if k=4 , and we have single 2 in the array then this can give wrong answer
            if( (k/curr) != curr && (umap[k/curr ] >1) )
            {
                cout << "Pair " << ptr ->data << " " << k/(ptr-> data) ;
                return true;
            }
        }
        ptr = ptr -> next;
    }
    return false;
}

int main()
{
    struct node* head = NULL;

    /*push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    push(&head, 18);
    push(&head, 47);
    push(&head, 16);
    push(&head, 12);
    push(&head, 14);
    int k=26;
*/
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    push(&head, 18);
    push(&head, 47);
    push(&head, 16);
    push(&head, 12);
    push(&head, 14);
    int k = 24;
    /* function to print the result*/
    bool res = check_pair_product(head, k);
    if (res == false)
        cout << "NO PAIR EXIST";

    return 0;
}
