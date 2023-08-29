/**
->Simple Backtracking -
    public:
    bool canTry(char c ,int i , int j, vector<vector<char>> board)
    {
        for(int k=0;k<9;k++)
        {
            if(board[i][k] == c)
                return false;
            if(board[k][j] == c)
                return false;
        }

        for(int t = (i/3) *3  ; t<(i/3)*3 + 3;t++)
        {
            for(int k = (j/3)*3 ; k<(j/3)*3 + 3;k++)
            {
                if(board[t][k] == c)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                        for(char c='1'; c<='9'; c++){
                            if(canTry(c,i , j ,board) )
                            {
                                board[i][j] = c;
                                if(solve(board))
                                    return true;
                                board[i][j] = '.';
                            }
                        }

                        return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

->Use of mapping instead of searching wether number can c be filled or not , can improve time complexity to
great extent. Try or see my submission

->Use of backtracking with bitmasking . Very fast . I dont know yet.
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu";
    return 0;
}
