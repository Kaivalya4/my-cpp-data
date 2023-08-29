/**
-> Construct a binary tree from levelorder and inorder traversal.

-> I wrote the solution  on my own . The upper bound ( not the exact time complexity )  is O(n^3) .



Node* solve(int start , int ends , int & n , int in[] , int le[]){
    if(start>ends)
        return NULL;
    Node* temp ;
    for(int i=0;i<n;i++){
        for(int j=start ; j<=ends ;j++){
            if(le[i] == in[j]){
                temp = new Node(le[i]);
                temp -> left = solve(start , j-1 , n , in  , le);
                temp -> right = solve(j+1 , ends , n , in  , le);
                return temp;
            }
        }
    }
    return temp;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    return solve(0 , n-1 , n , inorder , levelOrder);
}
*/
