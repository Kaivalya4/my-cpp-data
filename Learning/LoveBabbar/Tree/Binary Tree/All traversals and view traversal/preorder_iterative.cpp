/**
-> I solved it in one go , simple no explanation req. use your brain idiot !!!!

vector<int> preOrder(Node* root)
    {
        vector<int> sol;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* top = stk.top();
            stk.pop();
            sol.push_back(top -> data);

            ///push left at last so that its poped out first
            if(top -> right)
                stk.push(top -> right);
            if(top -> left)
                stk.push(top -> left);
        }
        return sol;
    }
*/
