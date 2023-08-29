/**
-> find distance between two nodes.

    Node* lca(Node* root , int n1 , int n2){
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

    int height(Node* root , int val ){
        if(root == NULL)
            return 0;

        if(root -> data == val){
            return 1;
        }

        int left= height(root -> left  ,val);
        int right = height(root -> right , val);

        if(left)
            return 1+left;
        if(right)
            return 1+right;
        return 0;
    }

    int findDist(Node* root, int a, int b) {
        Node* lcan = lca(root , a , b);
        int ha = height(root , a);
        int hb = height(root , b);
        int hlca = height(root , lcan -> data);

        return ha + hb -  2*hlca;
    }


-> One slight modification for slight time impovement . thought asymtotically time remains same.

    int findDist(Node* root, int a, int b) {
        Node* lcan = lca(root , a , b);
        int ha = height(lcan , a);
        int hb = height(lcan , b);

        return ha + hb - 2 ;
    }
*/
