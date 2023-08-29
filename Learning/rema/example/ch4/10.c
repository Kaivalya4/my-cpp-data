#include<stdio.h>
#include<string.h>
int main()
{
    char arr[5][30] ,temp[30];
    int i,n,j;
    printf("enter number of students : ");
    scanf("%d",&n);
    getchar();
    printf("\nenter name of students -------- ");
    for(i=0;i<n;i++)
    {
        printf("\nenter the name of student %d : ",i+1);
        gets(arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-i;j++)
        {
            if(strcmp(arr[i],arr[i+j])>0)
            {
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[i+j]);
                strcpy(arr[i+j],temp);
            }
        }
    }
    printf("\nnames of the students in alphabetical order : ");
    for(i=0;i<n;i++)
    {
        printf("\n");
        puts(arr[i]);
    }
    return 0;
}
