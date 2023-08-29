//Recursive	function	to	delete	k-th	node	from	linked	list
#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;

node* push(struct node* head , int data)
{
    if(head == NULL)
    {
        struct node* new_node = (struct node *)malloc(sizeof(struct node));
        new_node -> data = data;
        new_node -> next = NULL;
        head = new_node;
        return head;
    }
    node* ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    struct node* new_node = new node;
    new_node -> data  = data;
    new_node -> next = NULL;
    ptr -> next = new_node;
    return head;
}

node* solve(node* head , int k)
{
    if(head == NULL)
        return head;

    if(k<1)
        return head;

    if(k == 1)
    {
        node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    head -> next = solve(head -> next , k-1);
    return head;
}

void display(node* head )
{
    node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    return ;
}

int main()
{
    head= push(head,3);
    head = push(head,2);
    head = push(head,6);
    head = push(head,5);
    head = push(head,11);
    head = push(head,10);
    head = push(head,15);
    head = push(head,12);

    display(head);
    cout << endl;

    int k;
    cin >> k;

    head = solve(head , k);

    display(head);

    return 0;
}
