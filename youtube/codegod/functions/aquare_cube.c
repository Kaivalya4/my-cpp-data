#include<stdio.h>
int square(int);
int cube(int);
int main()
{
    int num;
    scanf("%d",&num);
    printf("square is -: %d\n",square(num));
    printf("cube is -: %d",cube(num));
    return 0;
}
int square(int n)
{
    return n*n;
}
int cube(int n)
{
    return n*n*n;
}
