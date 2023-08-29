/**

-> Push curr then make curr = curr -> left
-> The moment we get curr == NULL , it means that we reach one leaf => pop its parent from stack , print it,
    make curr = parent -> right.

    Note : if parent -> right == NULL another pop happens and this time its another ancestor which should have
    printed when we did inorder recursively


vector<int> inOrder(Node* root)
    {
        vector<int> sol;
        Node* curr = root;
        stack<Node*> stk;
        while(!stk.empty() || curr){
            if(curr){
                stk.push(curr);
                curr = curr -> left;
            }
            else{
                curr = stk.top();
                stk.pop();
                sol.push_back(curr -> data);
                curr  = curr -> right;
            }
        }
        return sol;
    }

*/
