#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct date
{
    int day,month,year;
};
struct credec
{
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    char phone[10];
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    struct date created;
}add,upd , check;
int menu();
void create();
void update();
void delay()
{
     int j=0;
     while(j!=100050000)
     {
        j++;
     }
}
void create()
{
    FILE *fp;
    fp=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t Creating Account ----- ");
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
        {
            printf("Account no. already in use!");
            delay();
            goto account_no;
        }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit: Rs. ");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t->Saving\n\t->Current\n\t->Fixed1(for 1 year)\n\t->Fixed2(for 2 years)\n\t->Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\n\n\nEnter Account creation date (today's date(mm/dd/yyyy)):");
    scanf("%d/%d/%d",&add.created.month,&add.created.day,&add.created.year);

        fprintf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.created.month,add.deposit.day,add.created);


    fclose(fp);
    printf("\nAccount created successfully!");
    printf("\nPress Any key to return to main menu .");
    getchar();
}
/*void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}*/
void update(void)
{
    int choice,sign=0,resp;
    FILE *old,*neww;
    old=fopen("record.dat","r");
    neww=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   sign=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(neww,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(neww,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(neww,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(neww);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(sign!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
        edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&resp);
        system("cls");
        if (resp==1)
            menu();
        else if (resp==2)
            exit(0);
        else if(resp==0)
            update();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    printf("\n\n\tPress any key to return to main menu : ");
    getchar();
}
int menu()
{
    int choice ,i ;
    printf("\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM ---");
    printf("\n\t\t\t\tWELCOME TO THE MAIN MENU");
    printf("\n\n\n\t\t1.Create new account");
    printf("\n\n\t\t2.Update information of existing account");
    printf("\n\n\t\t3.For transactions");
    printf("\n\n\t\t4.Check the details of existing account");
    printf("\n\n\t\t5.Removing existing account");
    printf("\n\n\t\t6.View customer's list");
    printf("\n\n\t\t7.EXIT");
    printf("\n\n\nEnter your choice : ");
    scanf("%d",&choice);
    printf("\n\n\n\n\n\t\t\tLoading");
    for(i=0;i<6;i++)
    {
        delay();
        printf(".");
    }
    system("cls");
    switch(choice)
    {
        case 1: create();
                printf("\n\n\n\n\n\t\t\tLoading");
                for(int i=0;i<6;i++)
                {
                    delay();
                    printf(".");
                }
                break;
        case 2: update();
                printf("\n\n\n\n\n\tLoading");
                for(i=0;i<6;i++)
                {
                    delay();
                    printf(".");
                }
                break;
        case 3 : break;
    }
    menu();
    return 0;
}
int main()
{
    char pass[10],password[]="hanuman";
    printf("\t\tEnter password :  ");
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
    {
        printf("\n\nCorrect Password!");
        printf("\nLoading");
        for(int i=0;i<6;i++)
        {
           delay();
            printf(".");
        }
        system("cls");
        menu();
    }
    return 0;
}
