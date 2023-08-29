/**
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction

-> We use vector and find that how many answer we can find if the current node act as ending point.

    int ans =0;
    void solve(Node* root , vector<int> vec , int &k){
        if(root == NULL)
            return ;

        vec.push_back(root -> data);
        int sum = 0;
        for(int j=vec.size()-1;j>=0;j--){
            sum += vec[j];
            if(sum == k){
                ans++;
            }
        }
        solve(root -> left , vec , k);
        solve(root -> right , vec , k );
    }

    int sumK(Node *root,int k)
    {
        vector<int> vec;
        solve(root , vec, k );
        return ans;
    }
*/
