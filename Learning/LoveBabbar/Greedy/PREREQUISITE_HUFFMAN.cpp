/**
Huffman Coding is a technique of compressing data to reduce its size without
losing any of the details.It is generally useful to compress the data in which there are
frequently occuring characters.

->We know that every character is sequence of 0 and 1 and stored
    using 8-bits. This is known as FIXED LENGTH ENCODING , as each character uses the
    same number of fixed bit storage

->So if we can use VARIABLE LENGTH ENCODING then we can reduce storage space
    i.e. like if some character x appears more , assign it less bit or something like that.
    But there is a problem with variable length encoding - HOW TO DECODE ?

    ex - consider "aabacdab" } 8 characters => 8char * 8bits = 64 storage space.
    lets count frequency : a->4 , b->2 , c->1,d->1 . So based on frequency we designed an
    encoding :
        a : 0 , b : 11  , c : 100 , d: 011
    => aabacdab -> 00110100011011 .
    while decoding : 0| 011 | 0 | 100| 011 | 0 | 11  : adacdab
                     0| 0 | 11 | 0 | 100 | 0 | 11 | 011 : aabacabd
                     ...........and so on(so many decoding for single encodgin : ambiguity)

->PREFIX RULE : no code is a prefix of another code. (like 0 is prefix of 011 which violates rule)
    if our encode satisfy prefix rule , then decoding will be unambiguious(and vice versa)

->HUFFMAN CODING : variable length encoding satisfying prefix rule.
    :loseless data encoding for data compression.
    :considers weight or frequency into consideration and creates binary tree.
    :GREEDY -> more frequency has smallest code

    Tree : as a common convention, bit 0 represent following the left child, and 1 represents
    following the right child. A finished tree has n leaf nodes and n-1 internal node.

-> Time complexity - If string contains n distincts characters then tree will have n leaf node and
    n-1 internal node. Then total node = 2n-1 . Efficient priority queue do insertion and extraction in
    O(logn) time . Henc overall complexity is O(nlognn)

*/


#include<iostream>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;

struct node
{
    char c;
    int freq;
    node* left , *right;
};

///minheap on freq
struct comp
{
    ///while using comparator with priority queue , think like you are sorting
    bool operator()(node* a , node *b){
        if(a->freq < b->freq)
            return false;
        return true;
    }
};

node* makenode(char c , int freq , node*l , node*r)
{
    node* new_node = new node;

    new_node ->c = c;
    new_node -> freq = freq;
    new_node -> left = l;
    new_node -> right= r;

    return new_node;
}

bool isleaf(node* root)
{
    if(root -> left == NULL && root -> right == NULL)
        return true;
    return false;
}

void encoding(node* root , string str , unordered_map<char ,string> &encoded)
{
    if(root == NULL)
        return;

    if(isleaf(root))
    {
        encoded[root -> c] = str != "" ? str : "1";
    }

    encoding(root-> left , str + '0' , encoded);
    encoding(root ->right , str+'1' , encoded);
}

void decoding(node* root , int &index , string str)
{
    if(root == NULL)
        return ;
    if(isleaf(root))
    {
        cout << root -> c ;
        return;
    }
    index++;
    if(str[index] == '0')
        decoding(root -> left , index , str);
    else
        decoding(root -> right , index , str);
}

void Huffman(string text)
{
    if(text == "")
        return ;
    unordered_map<char , int> freqcount;
    for(int i=0;i<text.length();i++)
        freqcount[text[i]]++;

    priority_queue<node* , vector<node*> , comp> pq;

    for(auto i:freqcount)
    {
        pq.push( makenode(i.first , i.second , NULL ,NULL));
    }

    while(pq.size() !=1)
    {
        node* top1 = pq.top();
        pq.pop();
        node* top2 = pq.top();
        pq.pop();

        int val = top1-> freq + top2->freq;
        pq.push(makenode('\0' , val , top1 , top2));
    }
    node* root = pq.top();
    pq.pop();

    ///Tree has been built now , now lets store encoding for each characters

    unordered_map<char , string> encoded;
    encoding(root ,  "" , encoded);

    cout << "Encoding for characters are : " << endl;
    for(auto i:encoded)
    {
        cout << i.first << " -> " << i.second;
        cout << endl;
    }
    string str ;
    for(char c : text)
    {
        str += encoded[c];
    }

    cout << "Original string is : " << text << endl;
    cout << "Encoded strig is : " << str <<  endl;

    cout << "Decoding the encoded string to get original string  " << endl;

    if(isleaf(root))
    {
        while(root -> freq--)
        {
            cout << root -> c ;
        }
    }
    else{
        int index = -1;
        while(index <(int)str.size() -1)
            decoding(root , index ,str);
    }
}

int main()
{
    string s;
    getline(cin  ,s);
    Huffman(s);
    return 0;
}

