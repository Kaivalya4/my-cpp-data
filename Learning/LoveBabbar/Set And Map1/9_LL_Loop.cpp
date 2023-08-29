/*
So the main idea is detect the loop and remove it . So from all the method we know to detect the loop we can use
two method - Hashing , Floyd cycle detection because it will make our loop removal easy

method1 - Using hashing - we identified the node which occured again . we need to just make node before it null
very simple !!!!
O(n) time and space

method2 - Using Floyd cycle detection we can detect cycle but we cannot detect exact starting point of loop.
->1. we detect the loop i.e. tor = rab , start again from here and end again here counting number of nodes in loop k.
Start one pointer from head and another from kth node from head and move until we get common point and that will be
starting of loop
->2. Suppose tor = rab = ptr2 and let ptr1 = head . We move ptr2 to complete one cycle in loop and after each cycle
we move ptr one step . So after some cycle they will meet at a point and that point will be starting point of loop
*/

//method1

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

bool solve(node* head)
{
    unordered_map<int  ,int> umap;
    node* ptr = head;
    while(ptr -> next != NULL)
    {
        if(umap[ptr -> next -> data] == 1)
        {
            ptr -> next = NULL;
            return true;
        }
        umap[ptr -> data] = 1;
        ptr = ptr -> next;
    }
    return false;
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
