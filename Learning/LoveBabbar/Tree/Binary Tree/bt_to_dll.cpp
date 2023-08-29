/**

-> Convert Binary tree to doubly linked list inplace (inorder traversal fashion)
    Expected time : O(n) and space : O(h) in stack call
-> If we have allowed more extra space then we could have stored node in vector then our task would have been easy

-> Then I tried recursion ( we can solve it using recursion but I couldn't able to ) , So I solved using iterative
    inorder

    Node * bToDLL(Node *root)
    {
        stack<Node*> stk;
        Node* curr = root;
        Node* head;
        Node* prev = NULL;
        bool mark = false;
        while(!stk.empty() || curr){
            if(curr){
                stk.push(curr);
                curr = curr -> left;
            } else {
                curr = stk.top();
                if(!mark){
                    head = curr;
                    mark = true;
                }
                stk.pop();
                curr -> left = prev;
                if(prev != NULL)  //for the first time.
                    prev -> right = curr;
                prev = curr;
                curr = curr -> right;

            }
        }
        prev -> right = NULL;
        return head;
    }

*/
