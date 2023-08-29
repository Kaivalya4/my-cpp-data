/**

-> dry run on 1,2,3,4,5    (2*i + 1 relation )
-> No need of stack sol : we can directly push_back in ans and reverse it.

vector<int> postOrder(Node* node) {
        stack<Node*> traverse;
        stack<Node*> sol;

        traverse.push(node);
        Node* curr = node;

        while(!traverse.empty()){
            curr = traverse.top();
            sol.push(traverse.top());
            traverse.pop();

            if(curr -> left) {
                traverse.push(curr -> left);
            }
            if(curr -> right) {
                traverse.push(curr -> right);
            }

        }

        vector<int> ans;

        while(!sol.empty()){
            ans.push_back(sol.top() -> data);
            sol.pop();
        }

        return ans;
    }
*/
