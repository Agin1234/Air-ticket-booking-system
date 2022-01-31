// Airline Booking System

#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>

struct book
{
char name[20]; 
char month[20]; 
int cost;
}b;

int seat=80; 
void book(); 
void view();

int main ()
{
int ch;
 
do
{
printf("Wlecome to Airline Reservation System\n");

printf("1 Book Tickets\n"); 
printf("2 View Tickets\n"); 
printf("0 Exit\n ");

printf("\n Enter your choice :"); 
scanf("%d",&ch);

switch (ch)
{
case 1:
book(); 
break;
case 2:
view(); 
break;
case 0:
exit(0); 
break;

default:
printf("Wrong choice entered"); 
break;
}
}while(ch!=0);

return 0;
}
 
void book()	//booking tickets
{
FILE *fp; 
struct book b;
printf("Enter passenger name : "); 
scanf("%s",&b.name);
printf("Enter Month: "); 
scanf("%s",b.month); 
printf("Enter Ticket Price: "); 
scanf("%d",&b.cost);
fp=fopen("data.txt","a");

if(fp == NULL)
{
 printf("FIle not Found");
}
else
{
fprintf(fp," %s %s %d\n",b.name,b.month,b.cost); 
printf("Congratulations,Booking successfull");

printf("\n");
 
fclose(fp);
}
}


void view()	// viewing tickets
{

char ch; 
FILE *fp;
fp = fopen("data.txt","r"); 
if(fp == NULL)
{
 
printf("Not found !"); 
exit(1);

}
else
{
while( (ch=fgetc(fp))!= EOF ) printf("%c",ch);
 
fclose(fp);
}
}
