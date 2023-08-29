/**
I have solved using various ways with all having same asymptotic complexity but can differ in actual runtime

-> must see answer 3 where we first push right nodes istead of left nodes.

-> Answer 1

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    stack<vector<int>> stk;
    vector<int> sol;

    q.push(root);
    while(!q.empty()){
        int sizes = q.size();
        vector<int> temp;

        for(int i=0;i<sizes;i++){
            Node* t = q.front();
            q.pop();
            temp.push_back(t -> data);
            if(t -> left)
                q.push(t-> left);
            if(t -> right)
                q.push(t-> right);
        }

        stk.push(temp);
    }

    while(!stk.empty()){
        for(auto i:stk.top()){
            sol.push_back(i);
        }
        stk.pop();
    }

    return sol;

}

-> Answer 2

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    vector<int> sol;

    q.push(root);
    while(!q.empty()){
        int sizes = q.size();
        stack<int> stk;

        for(int i=0;i<sizes;i++){
            Node* t = q.front();
            q.pop();
            stk.push(t -> data);
            if(t -> left)
                q.push(t-> left);
            if(t -> right)
                q.push(t-> right);
        }

        while(!stk.empty()){
            sol.push_back(stk.top());
            stk.pop();
        }
    }
    reverse(sol.begin() , sol.end());
    return sol;

}


-> Answer 3 (best for me)

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    vector<int> sol;

    q.push(root);
    while(!q.empty()){
        int sizes = q.size();

        for(int i=0;i<sizes;i++){
            Node* t = q.front();
            q.pop();
            sol.push_back(t -> data);
            if(t -> right)
                q.push(t-> right);
            if(t -> left)
                q.push(t-> left);

        }
    }
    reverse(sol.begin() , sol.end());
    return sol;

}



*/
