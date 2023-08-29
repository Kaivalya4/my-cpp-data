/**

-> minimum number of swaps required to convert binary tree to binary search tree.

-> The solution is my own . Key idea: think of inorder traversal . inorder traversal of bst gives sorted array
    Now find the inorder traversal of given tree and match it with the sorted one . Keep on updating the value so you
    don't end up couting the double or there is any counting mistake


-> Follow up : minimum number of swaps required to make an array sorted

    void solve(int idx , vector<int> &vec , vector<int> &arr){
        if(idx >=arr.size())
            return;
        solve(idx*2 + 1  , vec , arr);
        vec.push_back(arr[idx]);
        solve(idx*2 + 2 , vec , arr);
    }
    int minSwaps(vector<int>&A, int n){
        vector<int> vec;
        solve(0 , vec, A );
        vector<int> temp = vec;
        int ctr =0;
        sort(temp.begin() , temp.end());
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[vec[i]] = i;
        }
        for(int i=0;i<n;i++){
            if(vec[i] != temp[i]){
                vec[m[temp[i]]] = vec[i];
                m[vec[i]] = m[temp[i]];
                ctr++;
            }
        }
        return ctr ;
    }
*/
