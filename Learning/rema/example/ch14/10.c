#include<stdio.h>
#include<math.h>
int largest(int arr[],int n)
{
    int large = -999,i;
    for(i=0;i<n;i++)
    {
        if(arr[i]>large)
            large = arr[i];
    }
    return large;
}
void radix(int arr[],int n)
{
    int bucket[10][10] ,nod = 0,rem,large, bucket_size[10] = {0} ,i,j,k,t,divisor;
    large = largest(arr,n);
    while(large !=0)
    {
        large = large / 10;
        nod++;
    }
    for(i=0;i<nod;i++)
    {
        for(j=0;j<n;j++)
        {
            divisor = pow(10,i);
            rem = (arr[j]/divisor) % 10;
            bucket[rem][bucket_size[rem]] = arr[j];
            bucket_size[rem] += 1;
        }
        t=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bucket_size[k];j++)
            {
                arr[t] = bucket[k][j];
                t++;
            }
        }
    }
}
int main()
{
    int arr[10] ,i,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\n");
    radix(arr,n);
    printf("\nArray after being sorted : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
