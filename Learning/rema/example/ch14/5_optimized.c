#include<stdio.h>
int main()
{
    int arr[10] , n , i ,j,k, temp,flag = 0;
    printf("Enter number of elements in the array : ");
    scanf("%d",&n);
    printf("\nEnter elemnts in the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nBUbble sort begins : \n");
    for(i=0;i<n;i++)
    {
        flag = 0;
        printf("\n");
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == 0)
            return 0;
        printf("After the %d pass element in the array are : ",i+1);
        for(k=0;k<n;k++)
        {
            printf("%d ",arr[k]);
        }
    }
    return 0;
}

