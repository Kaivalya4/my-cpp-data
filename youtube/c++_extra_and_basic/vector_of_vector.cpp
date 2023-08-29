#include<iostream>
#include<vector>

using namespace std;


/* visualize vector of vector as - 
{{} , {} , {} }
*/
int main()
{
    vector<vector<int>> matrix;
    vector<int> row;

    row.push_back(1);
    row.push_back(2);
    row.push_back(3);

    matrix.push_back(row);
    int rowsize = matrix.size();
    cout<< "number of rows in matrix " << rowsize;  // it will give total number of vectors in the given vectors i.e. number of rows
    cout<< endl << "number of columns in matrx "<< matrix[0].size(); //it will give number of elements in the first vector inside given vector 
                    //i.e. number of columns
    cout<<endl;

    return 0;
}