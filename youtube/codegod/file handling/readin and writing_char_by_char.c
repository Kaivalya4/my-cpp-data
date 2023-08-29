/*KEYWORDS AND FUNCTIONS WE USE---------
fopen()-opens the file
fclose()-close the file
getc()-gets character from the current index then move to next index
putc()- put character at the current index then move to next index
fgets()-reads a line from a file
fclose()-writes a line to a file
EOF-end of file keyword
NULL keyword

---modes used-
r=reading from a ile
w=writing to a file,contents are overwritten.creates new file if spevcified file do not exsists
a=add new content at the ened of the file.creates new file if specified file doe not exsist.

----note-we also use FILE *fp.fp(can be any name) is pointer of FILE type which points to a starting point of given location
*/
#include<stdio.h>
#include<stdlib.h>   //for exit(0)

int main()
{
    FILE *fp ;             //file pointer
    char fname[20];
    char ch;
    /*creating file*/
    printf("enter file name to be created : ");
    scanf("%s",fname);
    fp=fopen(fname,"w");
    if(fp==NULL)
    {
        printf("\nfile not created!! ");
        exit(0);
    }
    printf("\nfile created successfully!!");
    //writing to file
    printf("\nenter text to file...enter full stop to exit :\n");
    while((ch=getchar())!='.')                           //while(1)
    {                                                     //{ch=getchar;if(ch=='\n')exit(0)};putc(ch,fp);}
        putc(ch,fp);   //writing character into file
    }
    printf("\ndata written succesfully");
    fclose(fp);
    /*again openning file to read data*/
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("\ncant open the file!");
    }
    printf("contents in the file are -- \n");
    while((ch=getc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}
