/**
-> Check if tree has duplicate subtrees of size 2 or more.

-> Since we can't use vector with maps , we have used strings. to seperate two nodes we have used '+' and for NUll we
have used '*' ( if we dont use '*' the two tree whose structure is different but whose preorder is same will give wrong
               answer ) .

    But we will avoid use of '*' with leaf node.


    bool ans = false;
    string solve(Node* root , map<string , bool> &m){
        if(!root )
            return "*";
        string s , s1;
        int val = root -> data;
        while(val){
            s1.push_back(val%10 + '0');
            val /=10;
        }
        reverse(s1.begin() , s1.end());
        s += s1;
        if(root -> left == NULL && root -> right == NULL){   ///leaf node handling.
            return s;
        }
        s.push_back('+');
        s += solve(root -> left , m);
        s.push_back('+');
        s += solve(root -> right , m);
        if(m[s])
            ans = true;
        m[s] = true;
        return s;
    }
    int dupSub(Node *root) {
        map<string  , bool> m;
        solve(root , m);
        return ans;
    }
*/
