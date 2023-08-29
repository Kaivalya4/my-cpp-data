/**
-> Build binary tree using given string.

-> solved on my own , but I brain stormed and dried run a lot to get the code correct.
-> my solution is O(n) time and space

Node* solve(int& idx  , string &str){
        if(idx >= str.length())
            return NULL;

        if(str[idx] == '('){
            idx++;
        }
        if(str[idx] == ')'){
            idx++;
            return NULL;
        }
        int num = 0;
        while(idx < str.length() && str[idx] != ')' && str[idx] != '(')
            num = num*10 + str[idx] - '0' , idx++;
        Node* temp = new Node(num );
        temp -> left = solve(idx ,  str);
        if(temp -> left == NULL){  /// No need to check right child
            return temp;
        }
        temp -> right = solve(idx ,str);
        if(temp -> right != NULL)   /// for something like (1(2)(3)) . if not done then pointer will point last ')' , but it should point one after.
            idx++;
        return temp;

    }

    Node *treeFromString(string str)
    {
        int idx = 0;
        return solve(idx  , str);
    }
*/
