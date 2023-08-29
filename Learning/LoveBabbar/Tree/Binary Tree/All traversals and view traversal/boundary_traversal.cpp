/**

-> For left boundary : solve1
-> For leaf nodes : solve2
-> For right boundary : solve3

-> Also see techiedelight

void solve1(Node* root , vector<int> & sol){
        if(root == NULL || (root -> left == NULL && root -> right == NULL ))
            return ;
        sol.push_back(root -> data);
        solve1(root -> left , sol);
        if(root -> left == NULL)
            solve1(root -> right , sol);
    }

    void solve2(Node* root , vector<int> &sol){
        if(root == NULL)
            return ;
        if(root -> left == NULL && root -> right == NULL)
        {
            sol.push_back(root -> data);
            return ;
        }
        solve2(root -> left , sol);
        solve2(root -> right , sol);
    }

    void solve3(Node* root , vector<int> &sol){
        if(root == NULL || (root -> left == NULL && root -> right == NULL))
            return ;
        solve3(root -> right , sol);
        if(root -> right == NULL)
            solve3(root -> left , sol);
        sol.push_back(root -> data);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> sol;
        if(root -> left == NULL && root -> right == NULL)
        {
            sol.push_back(root -> data);
            return sol;
        }
        if(root -> left == NULL){
            sol.push_back(root -> data);
            solve2(root , sol);
            solve3(root -> right , sol);
        } else {
            solve1(root , sol);
            solve2(root , sol);
            solve3(root -> right , sol);
        }
        return sol;
    }
*/
