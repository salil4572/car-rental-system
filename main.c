#include <stdio.h>
#include "conio2.h"
#include "car.h"
#include <string.h>
#include<stdlib.h>
int main()
{
    system("COLOR a2");
    int i,type,k,choice;
    int result;
    User*usr;
    gotoxy(25,10);
    textcolor(4);
    printf("WELCOME TO CAR RENTEL SYSTEM");
    gotoxy(20,14);
    textcolor(LIGHTRED);
    printf("* RENT A CAR AND WHEREVER YOU NEED *");
    getch();
    textcolor(BROWN);
    addAdmin();
    while(1)
    {
        clrscr();
        gotoxy(30,2);
        system("COLOR a2");
        textcolor(LIGHTRED);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,8);
        textcolor(BROWN);
        for(i=1;i<80;i++)
          {
            printf("*");
          }
         gotoxy(1,17);
         textcolor(BROWN);
         for(i=1;i<80;i++)
           {
            printf("*");
           }
            getch();
            gotoxy(30,9);
           textcolor(BROWN);
           printf("1.Admin");
            gotoxy(30,11);
           textcolor(BROWN);
           printf("2.Empolyee");
            gotoxy(30,13);
           textcolor(BROWN);
           printf("3.Exit");
           gotoxy(32,16);
           textcolor(WHITE);
           printf("select your Role:");
           do
           {
               scanf("%d",&type);

               k=0;
           if(type==1)
           {
              do{

          //  *code for admin login*
            usr=getinput();
            if(usr==NULL)
              break;
            else
            {
                k=chekUserExist(*usr,"admin");

            }

            }
                while(k==0);
                if(k==-1)
                   break;
                if(k==1)
            {
                gotoxy(1,20);
                textcolor(WHITE);
                printf("PRESS ANY KEY TO CONTINUE.");
                getch();

                while(1)
            {
                clrscr();
                choice=adminMenu();
                if(choice==7)
            {   clrscr();
                break;
            }
                switch(choice)
            {
                case 1:
                        clrscr();
                        addEmployee();
                        break;
                case 2:
                       clrscr();
                       addCarDetails();

                    break;
                case 3:
                       clrscr();
                       showCarDetails();

                    break;
                case 4:
                       clrscr();
                       viewEmpolyee();
                    break;
                case 5:
                       clrscr();
                       result=deleteEmp();
                       gotoxy(15,14);
                    if(result==0)
                {
                        textcolor(LIGHTRED);
                        printf("SORRY NOT RECORDED GIVEN EMP FOUND");
                }
                    else if(result==1)
                {
                        textcolor(LIGHTGREEN);
                        printf("Record delete seccessfully");
                }
                    else if(result==2)
                {

                        textcolor(LIGHTRED);
                        printf("Error in deletation.");
                }
                       textcolor(WHITE);
                       printf("\n Press any key to go back to the main menu.");
                       getch();
                    break;
                case 6:
                        clrscr();
                        deleteCarModel();
                    break;
                default:
                         textcolor(LIGHTRED);
                         printf("Incorrect Choice.");

                   }
                }
           }
           }
           else if(type==2)
           {
               //*code  for employ login
            do
        {
            usr=getinput();
            if(usr==NULL)
            break;
            else
        {
            k=chekUserExist(*usr,"emp");

        }

        }while(k==0);
            if(k==-1)
            break;
            if(k==1)
        {
            gotoxy(1,20);
            textcolor(WHITE);
            printf("PRESS ANY KEY TO CONTINUE.");
            getch();

    while(1)
        {
            clrscr();
            choice=empMenu();

    if(choice==6)
        {
            clrscr();
            break;

        }
            switch(choice)
        {
    case 1:
            clrscr();
            int rent;
            rent=rentCar();
            if(rent==-2)
        {
            gotoxy(35,9);
            textcolor(LIGHTRED);
            printf("sorry can not booked car .try again later");
            getch();
        }
            else if(rent==0)
        {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("You did not choose any car");
            getch();
        }
            break;
    case 2:
            clrscr();
            bookedCarDetails();
            getch();
            break;
    case 3:
            clrscr();
            availCarDetails();
            getch();
            break;
    case 4:
            clrscr();
            showCarDetails();
            getch();
            break;
      case 5:
          clrscr();
          returnCar();
           getch();
      break;
    default:
            printf("Enter a valoide key choice incorrect.");
            getch();
        }
      }
     }
   }
        else if(type==3)
       {
            clrscr();
            textcolor(LIGHTGREEN);
            gotoxy(25,12);
            printf("Thank you for using this application.");
            getch();
            exit(0);
       }
         else
       {
            textcolor(LIGHTRED);
            gotoxy(30,20);
            printf("INVALED CHOICE.");
            getch();
            gotoxy(30,20);
            printf("\t\t\t");
            gotoxy(49,16);
            printf("\t\t\t");
            gotoxy(49,16);
            textcolor(WHITE);
        }

    }
        while(1);

    }

    return 0;
}
