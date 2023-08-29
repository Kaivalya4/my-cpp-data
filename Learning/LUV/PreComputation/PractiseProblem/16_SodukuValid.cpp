//we number the subbox from 0 to 8(9*9 box has 9 3*3 box , we provide identification number to these 3*3 subboxes - 0,1,2,3,4,5,6,7,8)
//to calculate these box number or box identification number = ((i/3)*3) + (j/3)
//if any string is occur twice in map then sudoku is not valid



/*
bool isValidSudoku(vector<vector<char>>& board) {
        string str;
        unordered_map<string,int> umap;
        for (int i=0 ;i<9 ;i++)
        {
            str = "";
            for(int j=0 ;j<9 ;j++)
            {
                if(isdigit(board[i][j])){
                    int box = ((i/3)*3) + (j/3);
                    str = "box";
                    str.push_back(48+box);
                    char ch = 48+box;
                    cout << ch << endl;
                    str.push_back(board[i][j]);
                    if(umap[str] == 1)
                        return false;
                    umap[str] = 1;
                    str = "row";
                    str.push_back(48+i);
                    str.push_back(board[i][j]);
                    if(umap[str] == 1)
                        return false;
                    umap[str]= 1;
                    str = "col";
                    str.push_back(48+j);
                    str.push_back(board[i][j]);
                    if(umap[str] == 1)
                        return false;
                    umap[str] = 1;
                }
            }
        }
        return true;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";
    return 0;
}

