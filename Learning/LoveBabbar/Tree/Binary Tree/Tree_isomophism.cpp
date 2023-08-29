/**
-> root data should match otherwise non isomorphic
    if swapping is done
        Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.
    else
        Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2.
    if both the case return false then not isomorphic

    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1 == NULL && root2 != NULL)
            return false;
        if(root1 != NULL && root2 == NULL)
            return false;
        if(root1 == NULL && root2 == NULL)
            return true;

        if(root1 -> data  != root2 -> data)
            return false;

        bool ans1 = isIsomorphic(root1-> left , root2 -> left) && isIsomorphic(root1-> right , root2 -> right);
        bool ans2 = isIsomorphic(root1 -> right , root2 -> left) && isIsomorphic(root1 -> left , root2 -> right);
        return ans1 || ans2;
    }

*/
