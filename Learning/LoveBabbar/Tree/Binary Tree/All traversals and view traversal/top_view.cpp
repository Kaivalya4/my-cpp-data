/**
Solution : Print first element from top for every vertical line
            i.e. For every horizontal distance print the element whose level is least

We can use customize any vertical order traversal solution to solve this problem (keeping time complexity in mind)

Level order traversal solution :

vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node* , int>>q ;
        vector<int> sol;
        q.push({root  , 0});
        map<int,int> m;
        while(!q.empty()){
            int sizes = q.size();

            for(int i=0;i<sizes ; i++){
                pair<Node*,int> p  = q.front();
                q.pop();
                if(!m[p.second]){
                    m[p.second] = p.first -> data;
                }
                if(p.first -> left != NULL )
                    q.push({p.first -> left , p.second -1 });
                if(p.first -> right != NULL)
                    q.push({p.first -> right , p.second + 1});
            }
        }

        for(auto i:m)
            sol.push_back(i.second);

        return sol;
    }
*/
