/**
Brute Force
->mins to store the minimum horizontal distance from root, maxi to store maximum
->All the nodes which are at same horizontal distance from root will lie on one vertical line
->We can store the solution directly , but we want to print the value on one line from top to bottom . So we use another
    map(which stores the data in sorted order) inside our map for storing.
->O(n^2) time and O(n) space. w=widht of tree , h = height of tree.

    map<int,map<int,vector<int>>> m;
    void minmax(Node* root , int &mins , int &maxi, int val){
        if(root == NULL)
            return;
        if(mins > val)
            mins = val;
        else if(maxi < val)
            maxi = val;
        minmax(root -> left , mins , maxi , val-1);
        minmax(root -> right , mins, maxi , val+1);
    }

    void dfs(Node* root , int hd , int curr , int vd){
        if(root == NULL)
            return;
        if(hd == curr)
            m[hd][vd].push_back(root -> data);
        dfs(root -> left , hd , curr-1 , vd+1);
        dfs(root -> right , hd , curr+1 , vd+1);
    }

    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        int mins = 0 , maxi = 0;
        minmax(root ,mins ,  maxi , 0);
        for(int i=mins;i<=maxi;i++){
            dfs(root , i , 0 , 0);
        }
        vector<int> sol;
        for(auto i:m){
            for(auto j:i.second){
                for(auto k:j.second)
                    sol.push_back(k);
            }
        }
        return sol;
    }
*/

/**
Optimization 1 :
Use map  instead of calculating mins and maxi => Problem is that it will not give output in required order level wise

Optimiaztion 1.1 :
Use map of map like above instead of calculating mins and maxi.
O(n*logn*logn) time because of average access time of map . O(n) space

map<int,map<int,vector<int>>> m;
    void minmax(Node* root ,  int val , int vd){
        if(root == NULL)
            return;
        m[val][vd].push_back(root -> data);
        minmax(root -> left, val-1 , vd+1);
        minmax(root -> right  , val+1 , vd+1);
    }


    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        minmax(root , 0 , 0);
        vector<int> sol;
        for(auto i:m){
            for(auto j:i.second){
                for(auto k:j.second)
                    sol.push_back(k);
            }
        }
        return sol;
    }

*/

/**
Optimization 2 : Level order traversal.
O(nlogn) time due to access time of map . approx O(n) space.

vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> sol;
        queue<pair<Node*,int>> q;
        map<int,vector<int>> m;
        q.push({root,0});
        while(!q.empty()){
            int sizes = q.size();

            for(int i=0;i<sizes;i++){
                pair<Node*,int> p = q.front();
                q.pop();
                m[p.second].push_back(p.first -> data);
                if(p.first -> left != NULL)
                    q.push({p.first -> left , p.second - 1});
                if(p.first -> right != NULL)
                    q.push({p.first -> right, p.second + 1});
            }
        }
        for(auto i:m){
            for(auto j:i.second)
                sol.push_back(j);
        }
        return sol;
    }

Optimization 3 : unordered_map can decrease average time complexity from O(n) to O(1) but will have worst time
complexity of O(n).
If we use unordered_map then we will have to use mins and maxi to store optimal horizontal distances.
then
    for(int i=mins ; i<=maxi ; i++){
        for(auto j:umap[i])
            sol.push_back(j);
    }
*/


