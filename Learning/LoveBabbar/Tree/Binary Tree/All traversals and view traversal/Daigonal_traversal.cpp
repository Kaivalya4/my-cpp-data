/**

See techiedelight's image and explanation for better understanding

-> on going left increase daigonal number by 1 and on going to right child daigonal number remain as it is


void solve(Node* root , int daigonal , map<int,vector<int>> &m){
    if(root == NULL)
        return ;

    m[daigonal].push_back( root -> data);

    solve(root -> left , daigonal +1 , m);
    solve(root -> right , daigonal , m);
}

vector<int> diagonal(Node *root)
{
   vector<int> vec;
   map<int,vector<int>> m;

   solve(root , 1 , m);

   for(auto i:m){
       for(auto j:i.second)
        vec.push_back(j);
   }

   return vec;
}
*/
