/**

Given a binary tree, find if it is height balanced or not.
A tree is height balanced if difference between heights of
left and right subtrees is not more than one for all nodes of tree.


bool ans = true;

    int solve(Node* root){
        if(root == NULL)
            return 0;
        int left = 1+ solve(root -> left);
        int right = 1+solve(root -> right);

        if(abs(left - right) >1)
            ans = false;

        return max(left , right);
    }

    bool isBalanced(Node *root)
    {
        solve(root);
        return ans;
    }
*/
