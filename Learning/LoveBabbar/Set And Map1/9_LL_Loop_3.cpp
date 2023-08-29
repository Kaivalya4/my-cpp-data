//method2_1

#include<iostream>
#include<unordered_map>

using namespace std;

struct node{
    int data;
    struct node* next;
};

node* newNode(int data)
{
    node* new_node = new node;
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

void print(node * head)
{
    node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
}

int looplength(node* tor)
{
    int ctr = 0;
    node* ptr = tor;
    ptr = ptr -> next;
    ctr = 1;
    while(ptr != tor)
    {
        ctr++;
        ptr = ptr -> next;
    }
    return ctr;
}

void removes(node* head , int ctr)
{
    node* ptr1 = head;
    node* ptr2 = head;
    while(ctr != 1)
    {
        ctr--;
        ptr2 = ptr2 -> next;
    }
    while(ptr2 -> next != ptr1)
    {
        ptr2 = ptr2 -> next;
        ptr1 = ptr1 -> next;
    }
    ptr2 -> next = NULL;
}

bool solve(node* head)
{
    node* tor = head;
    node* rab = head;

    while(tor && rab && rab -> next)
    {
        tor = tor -> next ;
        rab = rab -> next -> next;
        if(tor == rab)
        {
            int counts = looplength(tor);
            removes(head , counts);
            return true;
        }
    }
    return false;
}

int main()
{
    node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    cout << "Loop exsist in LL : " << solve(head);

    cout << "\nLL after loop removal : " << endl;
    print(head);
    return 0;

}

