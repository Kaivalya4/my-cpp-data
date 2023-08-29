#include<stdio.h>


void func(int *x){
    int *y = x;
    printf("%d",y);
}

int main()
{
    int x;
    x = 10;
    func(&x);
    return 0;
}
