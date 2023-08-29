//We can use brute force also
//here we are using hashing

#include<iostream>
#include<unordered_map>

using namespace std;

struct node{
    int data;
    struct node* next;
};

void solve(struct node* head , int k)
{
    node* ptr = head;
    unordered_map<int , int > umap;
    while(ptr != NULL)
    {
        umap[ptr -> data] = 1;
        ptr = ptr -> next;
    }
    ptr = head;
    while(ptr != NULL)
    {
        int data = ptr -> data;
        if(umap[k /data] == 1 && k%data == 0){
            int data2 = k/data;
            cout << "(" << data << "," << data2 << ")";
            return ;
        }
        ptr = ptr -> next;
    }
    cout << "no pair exsists" ;
}

void push(struct node **head , int val)
{
    struct node* new_node = new node;
    new_node -> data = val;
    if((*head) == NULL)
    {
        new_node -> next  = NULL;
        (*head) = new_node;
        return;
    }
    node* ptr = (*head);
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> next = new_node;
    new_node -> next = NULL;
}

int main()
{
    struct node* head = NULL;

    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    push(&head, 18);
    push(&head, 47);
    push(&head, 16);
    push(&head, 12);
    push(&head, 14);

    solve(head , 26);

    return 0;
}
