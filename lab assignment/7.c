#include<stdlib.h>
#include<stdio.h>
struct employee
{
    int emp_no;
    char name[20];
    int salary;
}emp[10];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter employee_no : ");
        scanf("%d",&emp[i].emp_no);
        printf("enter name : ");
        scanf("%s",emp[i].name);
        printf("\nenter slary: ");
        scanf("%d",&emp[i].salary);
    }
    for(int i=0 ;i<n; i++)
    {
        printf("\nemployee number : %d",emp[i].emp_no);
        printf("\n name : %s \n",emp[i].name);
        printf(" salary:%d \n",emp[i].salary);
    }
     return 0;
}
