/**

Note - bottom most then right most

-> My own solution using level order traversal + mapping

    - umap to store the parent
    - lefts to store wether the node is left child of its parent or not

    struct Node* deletionBT(struct Node* root, int key)
{
    Node* head = root;
    queue<Node*> q;
    map<Node*,Node*> umap;
    map<Node* , bool> lefts;
    q.push(root);
    Node* todel;
    Node* br;
    while(!q.empty()){
        int sizes = q.size();
        for(int i=0;i<sizes;i++){
            Node* temp = q.front();
            q.pop();
            if(temp -> data == key){
                todel = temp;
            }
            if(i == sizes -1){
                br = temp ;
            }
            if(temp -> left){
                q.push(temp -> left);
                umap[temp -> left] = temp;
                lefts[temp -> left] = true;
            }
            if(temp -> right){
                q.push(temp -> right);
                umap[temp -> right] = temp;
            }
        }
    }
    todel -> data = br -> data;
    if(lefts[br]){
        umap[br] -> left = NULL;
    } else{
        umap[br] -> right = NULL;
    }
    delete br;
    return head;
}


-> Improvement
    - last will store the the parent of bottom most right most child
    - temp stores the last most element of queue which is ultimately bottom most right most child

    struct Node* deletionBT(struct Node* root, int key)
{
    queue<node*>q;
    q.push(root);
    Node*temp;
    Node*del,*last;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            temp = q.front();
            q.pop();

            if(temp->data == key)
            del = temp;

            if(temp->left)
            {
                last = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                last = temp;
                q.push(temp->right);
            }
        }
    }
    del->data = temp->data;
    last->right==temp?last->right=NULL:last->left=NULL;
    return root;
}

*/
