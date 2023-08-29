/**

-> Maximum sum of Non-adjacent nodes

-> used map for dp otherwise tle

    map<Node* , int> m;

    int solve(Node* root ){

        if(root == NULL)
            return 0;

        if(m[root])
            return m[root];

        ///root is included then we call grandchildrean
        int withsum = root -> data;
        if(root -> left)
        {
            withsum += solve(root -> left -> left);
            withsum += solve(root -> left -> right);
        }

        if(root -> right ){
            withsum += solve(root -> right -> left);
            withsum += solve(root -> right -> right);
        }

        ///if we not included root then we call children
        int without = solve(root -> left) + solve(root -> right);

        return m[root] = max(withsum , without);
    }

    int getMaxSum(Node *root)
    {
         return solve(root );
    }
*/
