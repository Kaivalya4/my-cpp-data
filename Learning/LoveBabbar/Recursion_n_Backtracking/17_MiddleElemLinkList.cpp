#include<iostream>

using namespace std;
struct node{
    int data;
    struct node *next;
};
node* head = NULL;

node* newLNode(int data)
{
    node* new_node = new node;
    new_node -> next = NULL;
    new_node -> data = data;
    return new_node;
}


node* solve(node* head , int ind)
{
    if(ind == 1)
    {
        node* ptr = head -> next;
        free(head);
        return ptr;
    }
    head -> next = solve(head -> next , ind-1);
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
    head = newLNode(1);
    head->next = newLNode(2);
    head->next->next = newLNode(3);
    head->next->next->next = newLNode(4);
    head->next->next->next->next = newLNode(5);

    display(head);
    cout << endl;

    node* ptr = head;
    int len=0;
    while(ptr != NULL)  //length
    {
        len++;
        ptr = ptr -> next;
    }

    len = len/2 + 1; //middle
    head = solve(head , len);

    display(head);

    return 0;
}
