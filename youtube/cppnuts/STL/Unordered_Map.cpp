/*unordered_map<key , value>
-> it is an associative container that contains key-value pair with unique keys.
-> map uses red black tree while it unordered_map uses Hashing and stores value in bucket.
-> map is ordered(either asc. or desc.) but unordered_map is not sorted and hence here it gets its name
-> search , insertion , and removal have average constant time complexity as it uses hashing internally. Elements are organised in buckets . So computing the
   outcome of hash function for a particular key will reveal its location . This allows its fast access.
*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<int , char> umap = {{1 , 'a'} , {2 , 'b'}};
    //we have constant acess -
    cout<< umap[1] << endl;
    cout<< umap[2] << endl;

    umap[1] = 'c'; //fast update possible

    for(auto i:umap)
        cout<<i.first << " -> " << i.second << endl;

    auto value = umap.find(2); //find returns iterator to the position where key is present . if not found then it return iterator to umap.end()
    value != umap.end() ? cout<< "Found : " << value -> first << " -> " << value -> second << endl : cout<< "not found" << endl;
    return 0;
}
