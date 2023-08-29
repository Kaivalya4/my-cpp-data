#include<stdio.h>
#include<stdlib.h>

int ht[10] , found = 0 ,key;

int hash_function(int val)
{
    return val%10;
}

void insert_key();
void search_key();
void delete_key();
void display();

int main()
{
    int choice , temp;
    for(int i=0 ; i<10 ; i++)
        ht[i] = -1;
    do
    {
        printf("\n1.Enter the key . ");
        printf("\n2.Search for the key . ");
        printf("\n3.Delete the key . ");
        printf("\n4.Display .");
        printf("\n5.Exit .");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert_key();
                     break;
            case 2 : printf("\nEnter the value to be searched : ");
                     scanf("%d" , &temp);
                     search_key(temp);
                     break;
            case 3 : delete_key();
                     break;

            case 4 : display();
                     break;

            case 5 : exit(0);

            default : printf("Enter any valid choice ! ");
        }

    }while(choice!=5);
    return 0;
}
void insert_key()
{
    int val  , i;
    printf("Enter the value to be inserted : ");
    scanf("%d" , &val);
    key = hash_function(val);
    if(ht[key] == -1)
    {
        ht[key] = val;
        return;
    }
    else
    {
        if(key < 9)
        {
            for(i = key +1 ; i<10 ; i++)
            {
                if(ht[i] == -1)
                {
                    ht[i] = val;
                    return;
                }
            }
        }
        for(i =0 ; i<key ; i++)
        {
            if(ht[i] == -1)
            {
                ht[i] = val;
                return;
            }
        }
    }
}
void search_key(int val)
{
    key = hash_function(val);
    if(ht[key] == val)
    {
        found =1;
        printf("yup value is found at index : %d " , key);
        return;
    }
    else
    {
         if(key < 9)
        {
            for(int i = key +1 ; i<10 ; i++)
            {
                if(ht[i] == val)
                {
                    found = 1;
                    printf("yup value is found at index : %d " , i);
                    return;
                }
            }
        }
        for(int i =0 ; i<key ; i++)
        {
            if(ht[i] == val)
            {
                found = 1;
                printf("yup value is found at index : %d " , key);
                return;
            }
        }
    }
    found = 0;
    printf("Oops value not found !!!!");
}
void delete_key()
{
    int val;
    printf("\nEnter the vlaue to be deleted : ");
    scanf("%d" , &val);
    search_key(val);
    if(found == 1)
    {
        if(key!=-1)
        {
            printf("The element deleted is %d " , ht[key]);
            ht[key] = -1;
        }
    }
}
void display()
{
    printf("\n");
    for(int i=0 ; i<10 ; i++)
    {
        printf("%d -> %d \n" , i ,  ht[i]);
    }
}
