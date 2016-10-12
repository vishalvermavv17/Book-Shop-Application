#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char date[20],uname[20],bname[20],mno[15];
long int cost;
int n,i;

//function for writing entry of book into file

void write()
{
    FILE *fp;
    char dat[20],unam[20],bnam[20],mn[15];
    long int cos;

    printf("\n Enter date(dd-mm-yyyy)\t:");
    scanf("%s[\n]",dat);
    printf("\nEnter the Customer name\t:");
    scanf("%s[\n]",unam);
    printf("\nEnter the book name\t:");
    scanf("%s[\n]",bnam);
    printf("\nEnter the mobile number\t:");
    scanf("%s[\n]",mn);
    printf("\nEnter the cost of the book\t:");
    scanf("%ld",&cos);
    fp=fopen("Record.txt","a");

    fprintf(fp,"\n%s %s %s %s %ld\n",dat,unam,bnam,mn,cos);
    printf("\n\tRecord written successfully!!!");
    fclose(fp);
}

//function to search record by date
void display(char da[20])
{
    FILE *fp;
    int res;

    fp=fopen("Record.txt","r");

    while(fscanf(fp,"%s %s %s %s %ld\n",date,uname,bname,mno,&cost)!=EOF)
    {
        res=strcmp(date,da);
        if(res==0)
        {
            printf("\nCustomer Name= %s",uname);
            printf("\nMobile no.= %s",mno);
            printf("\nBook name= %s",bname);
            printf("\nCost of book= $%ld\n",cost);
        }
    }
    fclose(fp);
}

void main()
{
    char ch;
    char sdate[20];
    system("color FC");
    system("textxolor 0");

    do
    {
        system("cls");
        printf("\t ***WELCOME TO THE BOOK SHOP OF YMCA***\t\n");
        printf("\n Press 1 to create entry of new book sold");
        printf("\n Press 2 to display list of books sold on specific date");
        printf("\n Press any other key for exit");
        printf("\n Enter your choice:\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:write();
                    break;
            case 2:printf("Enter date(DD-MM-YYYY): ");
                    scanf("%s",sdate);
                    display(sdate);
                    break;
            default:printf("Invalid Selection");
        }
        getch();
    }
    while(ch>0&&ch<3);

}
