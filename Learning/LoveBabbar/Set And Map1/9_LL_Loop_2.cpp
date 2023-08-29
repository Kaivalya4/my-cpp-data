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

void removes(node* tor , node* head)
{
    node* ptr1 = head;
    node* ptr2 ;

    while(1)
    {
        ptr2 = tor;
        while((ptr2 -> next != tor) && (ptr2 -> next != ptr1))
        {
            ptr2 = ptr2 -> next;
        }
        if(ptr2 -> next == ptr1)
        {
            break;
        }
        ptr1 = ptr1 -> next;
    }
    ptr2 -> next = NULL;
    return;
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
            removes(tor , head);
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
