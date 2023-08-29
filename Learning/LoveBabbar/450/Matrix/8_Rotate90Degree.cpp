/**
gfg.practise --- rotate 90 degree anticlockwise
->Do dry run as suggested in code to grasp the concept
void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rotateby90(int n, int matrix[][n])
{
    for(int i=0;i<n;i++)     ///rotation around daigonal
    {
        for(int j=i;j<n;j++)
        {
            swap(&matrix[i][j] , &matrix[j][i]);
        }
    }
    for(int j=0;j<n;j++)   ///reverse each column
    {
        for(int i=0;i<n/2;i++)
        {
            swap(&matrix[i][j] , &matrix[n-i-1][j]);
        }
    }
}
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu";

    return 0;
}
