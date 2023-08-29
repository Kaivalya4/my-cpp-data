/**
First see PREREQUISITE_MagicSquare
-> find one magic square of 3*3 - either copy from internet or use Prerequisite to make that matrix . Then
find other 7 matrix using -
    - rotation along middle column = a1
    - rotation along middle row = a2
    - rotation along middle row of a1
    - transpose = a3
    - rotation along middle column of a3 = a4
    - rotation along middle row of a3
    - rotation along middle row of a4
 or, we can copy all values of other 7 matrix for 3*3 magic square

 Compare the given matrix with each matrix and check for min value
*/
///I am going to do copy work

#include<iostream>
#include<climits> ///for intmin and intmax

using namespace std;

int main()
{
    int s[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3 ;j++)
            cin >> s[i][j];
    }

    int m1[3][3] , m2[3][3] , m3[3][3] , m4[3][3] , m5[3][3] , m6[3][4] , m7[3][3] , m8[3][3];

    m1[0][0] = 8, m1[0][1] =1 , m1[0][2] =6 ;
    m1[1][0] = 3, m1[1][1] = 5, m1[1][2] = 7;
    m1[2][0] = 4, m1[2][1] = 9, m1[2][2] = 2;

    m2[0][0] = 6, m2[0][1] = 1, m2[0][2] = 8;
    m2[1][0] = 7, m2[1][1] = 5, m2[1][2] = 3;
    m2[2][0] = 2, m2[2][1] = 9, m2[2][2] = 4;

    m3[0][0] = 4, m3[0][1] = 9, m3[0][2] = 2;
    m3[1][0] = 3, m3[1][1] = 5, m3[1][2] = 7;
    m3[2][0] = 8, m3[2][1] = 1, m3[2][2] = 6;

    m4[0][0] = 2, m4[0][1] = 9, m4[0][2] = 4;
    m4[1][0] = 7, m4[1][1] = 5, m4[1][2] = 3;
    m4[2][0] = 6, m4[2][1] = 1, m4[2][2] = 8;

    m5[0][0] = 8, m5[0][1] = 3, m5[0][2] = 4;
    m5[1][0] = 1, m5[1][1] = 5, m5[1][2] = 9;
    m5[2][0] = 6, m5[2][1] = 7, m5[2][2] = 2;

    m6[0][0] = 4, m6[0][1] = 3, m6[0][2] = 8;
    m6[1][0] = 9, m6[1][1] = 5, m6[1][2] = 1;
    m6[2][0] = 2, m6[2][1] = 7, m6[2][2] = 6;

    m7[0][0] = 6, m7[0][1] = 7, m7[0][2] = 2;
    m7[1][0] = 1, m7[1][1] = 5, m7[1][2] = 9;
    m7[2][0] = 8, m7[2][1] = 3, m7[2][2] = 4;

    m8[0][0] = 2, m8[0][1] = 7, m8[0][2] = 6;
    m8[1][0] = 9, m8[1][1] = 5, m8[1][2] = 1;
    m8[2][0] = 4, m8[2][1] = 3, m8[2][2] = 8;

    int mins = INT_MAX;
    int mintrack = 0;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m1[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack = 0;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m2[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack = 0;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m3[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack = 0;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m4[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack = 0;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m5[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack =0;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m6[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack =0;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m7[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack =0 ;

    for(int i=0;i<3;i++)
    {
        for(int j=0 ; j<3 ;j++)
            mintrack += abs(s[i][j] - m8[i][j]);
    }
    mins = min(mins , mintrack);
    mintrack = 0;

    cout << mins << endl;
    return 0;
}
