#include<stdio.h>
int swap(int arr[],int n,int i)
{
    int j,temp,pos = i;
    for(j=i;j<n;j++)
    {
       if(arr[pos] > arr[j])
            pos = j;
    }
    return pos;
}
void selsort(int arr[],int n)
{
    int i,j,pos,temp;
    for(i=0;i<n;i++)
    {
        pos = swap(arr,n,i);
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
        printf("\nAfter the %d pass element in the array are : ",i+1);
        for(j=0;j<n;j++)
            printf("%d ",arr[j]);
    }
}
int main()
{
    int arr[10] ,i,temp,j,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elemnets of the array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nSelection sort begins :- ");
    selsort(arr,n);
    return 0;
}
