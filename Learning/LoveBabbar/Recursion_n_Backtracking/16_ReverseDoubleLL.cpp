#include<iostream>
#include<vector>

using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;

node* solve(node* head)
{
    if(head -> next == NULL)
    {
        head -> next = head -> prev ;
        head -> prev = NULL;
        return head;
    }
    node* ptr = solve(head -> next);
    head -> next = head -> prev;
    head -> prev = ptr;
    return ptr;
}

node* push(node*head , int data)
{
    if(head == NULL)
    {
        node* new_node = new node;
        new_node -> data = data;
        new_node -> next = NULL;
        new_node -> prev = NULL;
        head = new_node;
        return head;
    }
    node* ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    node* new_node = new node;
    new_node -> data = data;
    new_node -> prev = ptr;
    new_node -> next = NULL;
    ptr -> next = new_node;
    return head;
}

void display(node* head)
{
    node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}
int main()
{
    head = push(head, 2);
    head = push(head, 4);
    head = push(head, 8);
    head = push(head, 10);

    display(head);

    head = solve(head);

    display(head);

    return 0;
}
