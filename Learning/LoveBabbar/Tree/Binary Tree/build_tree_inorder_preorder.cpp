/**

Build a binary tree using inorder and preorder.

-> I coded the solution on my own

-> Instead of linear search of i at each step of recursion , we can use map.
    <value ,index> . Now traverse the inorder in buildTree function and store index in map.
    Then make call to solve.


Node* solve(int start  , int ends , int &idx ,  int in[] , int pre[] , int &n){
        if(start > ends || idx>=n)
            return NULL;
        int i ;
        for( i=start ; i<=ends ; i++){
            if(in[i] == pre[idx]){
                break;
            }
        }
        Node* temp = new Node(pre[idx]) ;
        idx++;
        temp -> left = solve(start , i-1 , idx , in , pre , n);
        if(temp -> left == NULL)
            temp -> right = solve(i+1 , ends , idx , in , pre , n);
        else{
            idx++;
            temp -> right = solve(i+1 , ends , idx , in , pre , n);
        }
        if(temp -> right == NULL)
            idx--;
        return temp;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        int idx = 0;
        Node* root = solve(0 , n-1 , idx ,  in , pre , n);
        return root;
    }
*/
