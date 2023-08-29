/**
-> Find lca in binary tree

-> One solution : traverse for one node and store path upto that node in vector . Similarly for second node .
    Now two pointer
    O(n) time and space.

    void solve(Node* root , int &n1 , bool &found ,  vector<Node*>&vec){
        if(found)
            return ;
        if(root == NULL)
            return ;

        if(root -> data == n1){
            vec.push_back(root);
            found = true;
            return ;
        }
        vec.push_back(root);
        solve(root -> left , n1 , found , vec);
        solve(root -> right , n1 , found ,vec);
        if(found == false)
            vec.pop_back();
    }

    Node* lca(Node* root ,int n1 ,int n2 )
    {
        vector<Node*> vec1 , vec2;
        bool found  = false;
        solve(root , n1 , found ,  vec1);
        found = false;
        solve(root , n2 , found , vec2);


        int i=0 , j = 0 ;
        Node* lca =root;
        while(i<vec1.size() && j<vec2.size()){
            if(vec1[i] == vec2[j]){
                lca = vec1[i];
                i++ , j++;
            } else{
                break;
            }
        }
        return lca;
    }


-> One traversal : if one of the node is found return that node .
    If the current node is lca (and not n1 and n2 )  then both the subtree return Not Null node.
    If lca is already found then one of the subtree will return Not Null .

    The problem is that if one of the n1 and n2 is only present then above algo will not give correct answer

    O(n) time and O(h) space.

        Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root == NULL)
            return root;

        if(root -> data == n1 || root -> data == n2)
            return root;

        Node* left= lca(root -> left , n1 , n2);
        Node* right = lca(root -> right , n1 , n2);

        if(left && right)
            return root;

        if(left== NULL)
            return right;

        return left;
    }
*/
