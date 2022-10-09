#include<stdio.h>
#include"car.h"
#include<stdlib.h>
#include"conio2.h"
#include<dos.h>
#include<string.h>
void addAdmin()
{

    FILE*fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"Abhi 1","1506","ravi"},{"Ansu1","anuj12","singh"}};
        fwrite(u,sizeof(u),1,fp);
    }fclose(fp);

}
    User*getinput()
    {
       int i;
       clrscr();
       textcolor(BROWN);
       gotoxy(32,1);
       printf("CAR RENTEL SYSTEM\n");

       for(i=0;i<=80;i++)
      printf("%c",247);
      gotoxy(32,5);
       printf("* LOGIN PANEL *");
       gotoxy(1,7);
       textcolor(CYAN);
       for(i=0;i<=80;i++)
       {
        printf("%c",247);
       } gotoxy(1,15);

       textcolor(CYAN);
       for(i=0;i<=80;i++)
          {

            printf("%c",247);
           } gotoxy(60,8);
            textcolor(WHITE);
            printf("PRESS 0 TO EXIT");
            textcolor(CYAN);
            gotoxy(25,10);
            printf("Enter user id:");
             fflush(stdin);
             static User u;
            fgets(u.userid,20,stdin);
            char *pos;
            pos=strchr(u.userid,'\n');
            if(pos!=NULL)
            {
                *pos='\0';
            }
            if(strcmp(u.userid,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(30,17);
                printf("Login  Cancelled!");
                getch();
                textcolor(BROWN);
                return NULL;
            }
            textcolor(CYAN);
            gotoxy(25,11);
            printf("Enter password:");
            fflush(stdin);
            i=0;
            textcolor(WHITE);
            for(;;)
            {
               u.pwd[i]=getch();
                if(u.pwd[i]==13)
                {
                    break;
                }
               else if(u.pwd[i]==8)
                {
                    printf("\b \b");
                    i=i-2;
                }
                else
                {
                    printf("%c",u.pwd[i]);
                    delay(1000);
                    printf("\b*");
                }


                i++;
            }
            u.pwd[i]='\0';
            if(strcmp(u.pwd,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(30,17);
                printf("LOGIN CANCELLED");
                getch();
                textcolor(BROWN);
                return NULL;
            }
            getch();
            return &u;
    }
    int chekUserExist(User u,char*usertype)
     {
     if(strlen(u.userid)==0||strlen(u.pwd)==0)
     {
         gotoxy(28,20);
         textcolor(LIGHTRED);
         printf("Both fields are mandatory . try again");
         getch();
         gotoxy(28,20);
         printf("\t\t\t\t\t\t");
         return 0;
     }

     FILE *fp;
      if(strcmp(usertype,"admin")==0)
    {
       fp=fopen("admin.bin","rb");
    }
     else
     {
         fp=fopen("emp.bin","rb");
     }
     if(fp==NULL)
     {
         gotoxy(28,20);
         textcolor(LIGHTRED);
         printf("SORRY CAN NOT OPEN FILE.");
         getch();
         gotoxy(28,20);
         printf("\t\t\t\t\t\t");
         return -1;
     }
     int found=0;
     User user;
     while(fread(&user,sizeof(user),1,fp)==1)
     {
         if((strcmp(u.userid,user.userid)==0)&&(strcmp(u.pwd,user.pwd)==0))
         {
             found=1;
             break;

         }
     }
         if(found==0)
         {
          gotoxy(28,20);
          textcolor(LIGHTRED);
           printf("Invalid user id password. please try again");
          getch();
          gotoxy(28,20);
          printf("\t\t\t\t");
          }
         else
        {
         gotoxy(28,20);
         textcolor(LIGHTGREEN);
         printf("Login Successful!");
         getch();
         gotoxy(28,20);
         printf("\t\t\t\t\t\t");
        }
         fclose(fp);
         return found;
    }
    int adminMenu()
    {

        int i,choice;
        textcolor(RED);
        gotoxy(29,2);
        printf("CAR RENTEL SYSTEM");
        textcolor(LIGHTGREEN);
        gotoxy(35,6);
        printf("Admin menu\n");
        for(i=0;i<=80;i++)
            printf("*");
        textcolor(BROWN);
         gotoxy(32,8);
        printf("1.Add car Employee");
        gotoxy(32,9);
        printf("2.Add car Details");
        gotoxy(32,10);
        printf("3.Show car details");
        gotoxy(32,11);
        printf("4.show Empolyee");
        gotoxy(32,12);
        printf("5.Delete Emoplyee");
        gotoxy(32,13);
        printf("6.Deltshow Car Details");
        gotoxy(32,14);
        printf("7.Exit");
        gotoxy(32,16);
        printf("Enter choice:");
        textcolor(WHITE);
        scanf("%d",&choice);
         return choice;
    }
    /*void addEmployee()
    {
      char empid[10]="EMP-";
      char temp[10];
      char choice;
      char *pos;
      User u;
      FILE *fp=fopen("emp.bin","ab+");
      fseek(fp,0,SEEK_END);
      int total_rec=ftell(fp)/sizeof(User);
      if (total_rec!=0)
      {
      fseek(fp,-60,SEEK_END);
      fread(temp,sizeof(temp),1,fp);
      printf("Temp is %s",temp);
      getch();
      pos=strchr(temp,'-');
      total_rec=atoi(pos+1);
      printf("total_rec is %d",total_rec);
      getch();
      }
      total_rec++;
      sprintf(temp,"Emp-%d",total_rec);

     fseek(fp,0,SEEK_END);
      do
      {
          clrscr();
          gotoxy(32,2);
          textcolor(LIGHTRED);
          printf("CAR RENTEL SYSTEM");
          textcolor(LIGHTGREEN);
          int i;
          gotoxy(1,3);
          for(i=0;i<=80;i++)
          printf("~");
          textcolor(WHITE);
          gotoxy(25,5);
          printf("******Add Employee Details******");
          getch();
        gotoxy(1,8);
        textcolor(BROWN);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char *pos;
        pos=strchr(u.name,'\n');
        if(pos==NULL)
        {
        *pos='\0';
        }
        textcolor(BROWN);
        printf("Enter Employee Pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos= strchr(u.pwd,'\n');
        if(pos!=NULL)
       {
           *pos='\0';
       }
        textcolor(BROWN);

        fwrite(&u,sizeof(u),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULLY");
        printf("\n EMPLOYEE ID IS: %s",u.userid);
        getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do YOU WANT TO ADD MORE EMPLOYEE(Y/N) :");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
            break;
        total_rec++;
        sprintf(u.userid,"EMP-%d",total_rec);
        strcpy(empid,"EMP-");
        sprintf(temp,"%d",total_rec);
        strcat(empid,temp);
        strcpy(u.userid,empid);

      }while(1);
         fclose(fp);
         getch();
      }*/
      void addEmployee()
{
    char temp[20];
    char choice;
    char *pos;
    User u;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    if(total_rec!=0)
    {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);

        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);

    }

    total_rec++;
    sprintf(u.userid,"EMP-%d",total_rec);
    fseek(fp,0,SEEK_END);
    do
    {
      clrscr();
      int i;
      gotoxy(32,2);
      textcolor(LIGHTRED);
      printf("CAR RENTAL SYSTEM\n");
      textcolor(LIGHTGREEN);
      for(i=0;i<80;i++)
       {
         printf("%C",175);
       }
      textcolor(WHITE);
      gotoxy(25,5);
      printf("** ADD EMPLOYEE DETAILS **");
      gotoxy(1,8);
      textcolor(BROWN);
      printf("Enter Employee Name:");
      fflush(stdin);
      textcolor(WHITE);
      fgets(u.name,20,stdin);
      char *pos;
      pos=strchr(u.name,'\n');
      if(pos!=NULL)
      {
        *pos='\0';
      }
      textcolor(BROWN);
      printf("Enter Employee Pasword:");
      fflush(stdin);
      textcolor(WHITE);
      fgets(u.pwd,20,stdin);
      pos=strchr(u.pwd,'\n');
      if(pos!=NULL)
      {
        *pos='\0';
      }
      fwrite(&u,sizeof(u),1,fp);
      gotoxy(30,15);
      textcolor(LIGHTGREEN);
      printf("EMPLOYEE ADDED SUCCESSFULLY\n");
      printf("Employee ID is %s",u.userid);
      getch();
      gotoxy(1,20);
      textcolor(LIGHTRED);
      printf("Do you want to add more employee (Y/N)? ");
      textcolor(WHITE);
      fflush(stdin);
      scanf("%c",&choice);
      if (choice=='n'||choice=='N')
        break;
      total_rec++;
      sprintf(u.userid,"EMP-%d",total_rec);
      getch();
    }while(1);
      fclose(fp);
}

    void  viewEmpolyee()
    {
        FILE *fp=fopen("emp.bin","rb");
        User ur;
        int i;
        textcolor(BROWN);
        gotoxy(32,1);
        printf("CAR RENTEL SYSTEM\n");
        for(i=1;i<=80;i++)
        {
         printf("%c",247);
        }
        gotoxy(31,5);
        printf("EMPLOYEE DETALS");
        gotoxy(1,7);
        textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
            printf("%c",247);
        if(fp==NULL)
        {
            gotoxy(31,9);
            textcolor(LIGHTRED);
            printf("Sorry! no Employee Added yet");
            getch();
            return ;
        }
        gotoxy(1,8);
        textcolor(LIGHTRED);
        printf("Employee id\t\t\tName\t\t\t password");
        gotoxy(1,9);
        for(i=0;i<=80;i++)
            printf("%c",247);
          int row=10;
          textcolor(BROWN);
     while(fread(&ur,sizeof(ur),1,fp)==1)
     {
       gotoxy(2,row);
       printf("%s",ur.userid);
       gotoxy(33,row);
       printf("%s",ur.name);
       gotoxy(57,row);
       printf("%s",ur.pwd);
       row++;
     }
      fclose(fp);
      getch();
}
int empMenu()
{
    int choice,i;
    clrscr();
    gotoxy(32,1);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(35,5);
    textcolor(BROWN);
    printf("EMPLOYEE MENU");
    gotoxy(1,6);
    for(i=0;i<=79;i++)
    {
        printf("%c",175);
    }
    gotoxy(32,8);
    textcolor(LIGHTGRAY);
    printf("1.Rent A Car");
    gotoxy(32,9);
    printf("2.Booking Details");
    gotoxy(32,10);
    printf("3.Available Car Details");
    gotoxy(32,11);
    printf("4.Show All Car Details");
    gotoxy(32,12);
    printf("5.returnCar");
     gotoxy(32,13);
    printf("6.Exit");
    gotoxy(1,14);
    textcolor(BROWN);
    for(i=0;i<=79;i++)
    {
        printf("%c",175);
    }
    textcolor(LIGHTMAGENTA);
    gotoxy(32,15);
    printf("Enter Choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;
}

void  showCarDetails()
    {
        FILE *fp=fopen("car.bin","rb");
        Car C;
        int i;
        textcolor(BROWN);
        gotoxy(32,1);
        printf("CAR RENTEL SYSTEM\n");
        for(i=1;i<=80;i++)
        {
         printf("%c",247);
        }
        gotoxy(31,5);
        printf("** ALL CAR DETALS **");
        gotoxy(1,7);
        textcolor(LIGHTGREEN);
        for(i=0;i<=80;i++)
            {
            printf("%c",247);
            }
            gotoxy(1,9);
        textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
            printf("%c",247);
        if(fp==NULL)
        {
            gotoxy(31,9);
            textcolor(LIGHTRED);
            printf("Sorry! no CAR Added yet");
            getch();
            return ;
        }
        gotoxy(1,8);
        textcolor(LIGHTRED);
        printf("CAR_id\t\tMODEL\tCapacity\tAvailable\t     Price/Day");
          int row=10;
          textcolor(BROWN);
     while(fread(&C,sizeof(C),1,fp)==1)
     {
       gotoxy(2,row);
       printf("%d",C.car_id);
       gotoxy(16,row);
       printf("%s",C.car_name);
       gotoxy(27,row);
       printf("%d",C.capacity);
       gotoxy(41,row);
       printf("%d",C.car_count);
       gotoxy(67,row);
       printf("%d",C.price);

       row++;
     }
       fclose(fp);
       getch();
}
int deleteEmp()
{
        FILE *fp1=fopen("emp.bin","rb");
        char empid[10];
        int result,i;

        textcolor(BROWN);
        gotoxy(32,1);
        printf("CAR RENTEL SYSTEM");
        for(i=0;i<=80;i++)
    {
        printf("%c",247);
    }
        gotoxy(29,5);
        printf("DELETE EMPLOYEE RECORD");
        gotoxy(1,7);
         textcolor(LIGHTGREEN);
      for(i=0;i<=80;i++)
    {
         printf("%c",247);
    }
         gotoxy(1,12);
         textcolor(LIGHTGREEN);
      for(i=0;i<=80;i++)
    {
          printf("%c",247);
    }
    if(fp1==NULL)

    {
         textcolor(LIGHTRED);
         gotoxy(32,10);
         printf("No EMPLOYEE ADDED YET");
         return -1;
    }
         FILE *fp=fopen("temp.bin","wb");
    if(fp==NULL)
{
         textcolor(LIGHTRED);
         gotoxy(32,10);
         printf("Sorry ! cannot create temp file");
         return -1;
}
        gotoxy(10,9);
        textcolor(BROWN);
        printf("ENTER employee id to delete file record");
        textcolor(WHITE);
        scanf("%s",empid);
        User u;
        int found=0;
        while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(u.userid,empid)!=0)
        fwrite(&u,sizeof(u),1,fp);
        else
            found=1;

    }
        fclose(fp1);
        fclose(fp);
        if(found==0)
    {
        remove("temp.bin");
    }
    else
    {
        result=remove("emp.bin");

    if(result!=0)
    {
        return 2;
        result=rename("temp.bin","emp.bin");
    }
    if(result!=0)
        return 2;
    }
     return found;

}

void addCarDetails()
{
     int i;
     char choice;
    char car_id[30]="Car-";
     char temp[20];
     Car C;
     FILE *fp=fopen("car.bin","ab+");
     fseek(fp,0,SEEK_END);
     long total_rec=ftell(fp)/sizeof(Car);
     total_rec++;

    do
      {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        gotoxy(1,3);
        textcolor(LIGHTMAGENTA);
        for(i=0;i<=79;i++)
        {
            printf("%c",175);
        }
        gotoxy(1,12);
        for(i=0;i<=79;i++)
        {
            printf("%c",174);
        }
        gotoxy(28,5);
        textcolor(LIGHTCYAN);
        printf("***** ADD CAR DETAILS *****");
        gotoxy(10,7);
        printf("Enter Car Name :");
        fflush(stdin);
        fgets(C.car_name,50,stdin);
        char *pos;
        pos=strchr(C.car_name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        gotoxy(10,8);
        printf("Enter Car Capacity:");
        scanf("%d",&C.capacity);
        gotoxy(10,9);
        printf("Enter Car Count:");
        scanf("%d",&C.car_count);
        gotoxy(10,10);
        printf("Enter Car price for per day:");
        scanf("%d",&C.price);
        C.car_id=total_rec;
        fwrite(&C,sizeof(C),1,fp);
        gotoxy(28,15);
        textcolor(BROWN);
        printf("CAR ADDED SUCCESSFULLY");
        gotoxy(5,16);
        printf("CAR ID IS :%d",C.car_id);
        gotoxy(24,19);
        textcolor(LIGHTRED);
        printf("DO YOU WANT TO ADD MORE CAR(Y/N) :");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
            break;
        total_rec++;
     }
       while(1);
       fclose(fp);
}

int deleteCarModel()
{
      int i,result;
     int carid;
    clrscr();
    gotoxy(32,1);
    textcolor(LIGHTGRAY);
    printf("* DELETE CAR RECORD *");
    gotoxy(1,3);
    textcolor(BROWN);
    for(i=0;i<=79;i++)
    {
       printf("%c",175);
    }
    gotoxy(1,10);
    for(i=0;i<=79;i++)
    {
       printf("%c",174);
    }
    gotoxy(15,5);
    textcolor(LIGHTGRAY);
    printf("Enter Car Model Id to delete the record:");
    scanf("%d",&carid);
    FILE *fp1,*fp2;
    fp1=fopen("car.bin","rb");
    if(fp1==NULL)
    {
        gotoxy(25,12);
        textcolor(LIGHTRED);
        printf("NO CAR ADDED YET!");
        return -1;
    }
    fp2=fopen("temp.bin","wb");
    if(fp2==NULL)
    {
        gotoxy(25,12);
        textcolor(LIGHTRED);
        printf("!Sorry File Cannot be Create");
        return -1 ;
    }
    int count=0;
    Car c;
    while(fread(&c,sizeof(c),1,fp1)==1)
    {
        if(c.car_id==carid)
            count++;
        else
            fwrite(&c,sizeof(c),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(count==0)
        remove("temp.bin");
    else
    {
        result=remove("car.bin");

        if(result!=0)
            return 2;
        result=rename("temp.bin","car.bin");

        if(result!=0)
            return -2;
    }
    textcolor(BROWN);
    gotoxy(25,12);
    printf("Record deleted Successfully");
    gotoxy(1,14);
    textcolor(WHITE);
    printf("Press any key to go back to the main screen !");
    getch();
    textcolor(LIGHTRED);
    gotoxy(1,16);
    return count;
}



  int rentCar()
{
    Customer_Car_Details cc;
   // char pick[30],drop[30];
    int i,x;
    clrscr();
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(34,6);
    textcolor(BROWN);
    printf("EMPLOYEE MENU");
    gotoxy(1,7);
    for(i=0;i<=80;i++)
    {
      printf("%c",175);
    }
    x=selectCarModel();
    if(x==0||x==-2)
    {
        return x;
    }
    cc.Car_id=x;
    clrscr();
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(34,6);
    textcolor(BROWN);
    printf("EMPLOYEE MENU");
    gotoxy(1,7);
    for(i=0;i<=80;i++)
      printf("%c",175);
    gotoxy(1,17);
    for(i=0;i<=80;i++)
        printf("%c",175);
    textcolor(10);
    gotoxy(25,9);
    char *pos;
    printf("Enter Customer Name:");
    textcolor(WHITE);
    fflush(stdin);
    fgets(cc.cust_name,30,stdin);
    pos=strchr(cc.cust_name,'\n');
    if(pos!=NULL)
      *pos='\0';
    textcolor(10);
    gotoxy(25,10);
    printf("Enter Pick up Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(cc.pick,30,stdin);
    pos=strchr(cc.pick,'\n');
      if(pos!=NULL)
        *pos='\0';
    gotoxy(25,11);
    textcolor(10);
    printf("Enter the Drop Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(cc.drop,30,stdin);
    pos=strchr(cc.drop,'\n');
    if(pos!=NULL)
        *pos='\0';
    gotoxy(25,12);
    textcolor(10);
    x=printf("Enter the Starting Date(dd/mm/year):");
    do
    {
        textcolor(WHITE);
        scanf("%d %d %d",&cc.sd.tm_wday,&cc.sd.tm_mon,&cc.sd.tm_year);
        int cv=isValidDate(cc.sd);
        int cvd=rentValidDate(cc.sd);
        if(cv==1&&cvd==1)
            break;
        gotoxy(32,19);
        textcolor(LIGHTRED);
        printf("Invalid Date");
        getch();
        gotoxy(32,19);
        printf("\t\t\t\t\t");
        gotoxy(x+25,12);
        printf("\t\t");
        gotoxy(x+25,12);
    }while(1);
    gotoxy(25,13);
    textcolor(10);
    printf("Enter the Ending Date(dd/mm/year):");//*ggggg*///
    do
    {
        textcolor(WHITE);
        scanf("%d %d %d",&cc.ed.tm_wday,&cc.ed.tm_mon,&cc.ed.tm_year);
        int cv=isValidDate(cc.ed);
        int cvd=checkSEDate(cc.sd,cc.ed);
        if(cv==1||cvd==1)
            break;
        gotoxy(32,19);
        textcolor(LIGHTRED);
        printf("Invalid Date");
        getch();
        gotoxy(32,19);
        printf("\t\t\t\t\t");
        gotoxy(x+25,13);
        printf("\t\t");
        gotoxy(x+25,13);

    }while(1);

     FILE *fp=fopen("Customer.bin","ab");
     if(fp==NULL)
     {
     //fwrite(&cc,sizeof(cc),1,fp);
     gotoxy(27,14);
     textcolor(LIGHTRED);
     //*printf("Booking Done is %d",cc.Car_id);
     printf("\n Sorry !File can not opened");
     getch();
     gotoxy(27,14);
      printf("\t\t");
       return -1;
       }
       fwrite(&cc,sizeof(Customer_Car_Details),1,fp);
       textcolor(WHITE);
       printf("Booking done for Car:%d",cc.Car_id);
       printf("\n press any key to continue...");
       getch();
       fclose(fp);
       updateCarCount(cc.Car_id);
       bookedCarDetails();

       return 1;

}


int selectCarModel()
{
    FILE *fp=fopen("car.bin","rb");
    int choice;
    int carcount=0;
    if(fp==NULL)
    {
        gotoxy(32,22);
        textcolor(LIGHTRED);
        printf("Sorry File Cannot Open at the Given Location");
        return 1;
    }
    Car C;
    int row=9;
    gotoxy(32,row);
    textcolor(LIGHTCYAN);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
         {
           printf("%d . %s",C.car_count,C.car_name);
           gotoxy(32,++row);
           carcount++;
         }
    }
    if(carcount==0)
    {
        fclose(fp);
        return -2;
   }
       gotoxy(32,row+2);
       int x;
        x=printf("Enter Your Choice:(0 to quit):");
      while(1)
    {
       textcolor(WHITE);
       scanf("%d",&choice);
       if(choice==0)
       {
           fclose(fp);
           return 0;
       }
       int temp=0;
       FILE *fp=fopen("car.bin","rb");
       rewind(fp);
       while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(choice==C.car_count&&C.car_count>0)
            {
                temp=1;
                break;
            }
        }
        if(temp==1)
        {
            fclose(fp);
            return choice;
        }
        gotoxy(34,row+4);
        textcolor(LIGHTRED);
        printf("WRONG INPUT");
        getch();
        gotoxy(34,row+4);
        printf("\t\t\t\t");
        gotoxy(x+32,row+2);
        printf("\t\t\t\t");
        gotoxy(x+32,row+2);
    }
}
int isValidDate(struct tm dt)
{
    if(dt.tm_year>=2000&&dt.tm_year<=2022)
    {
        if(dt.tm_mon>=1&&dt.tm_mon<=12)
        {
            if(dt.tm_wday>=1&&dt.tm_wday<=31&&(dt.tm_mon==1||dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==10||dt.tm_mon==12))
                return 1;
            else if(dt.tm_wday>=1&&dt.tm_wday<=30&&(dt.tm_mon==4||dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
                return 1;
            else if(dt.tm_wday>=1&&dt.tm_wday<=28&&dt.tm_mon==28)
                return 1;
            else if((dt.tm_wday>=1&&dt.tm_wday<=29)&&(dt.tm_year%400==0||(dt.tm_year%4==0&&dt.tm_year%100!=0)))
                return 1;
        }
    }
    return 0;
}
int rentValidDate(struct tm dt)
{
       time_t obj=time(0);
       struct tm *p=localtime(&obj);

       if(dt.tm_year>=1900+p->tm_year)
       {
           if(dt.tm_mon>=1+p->tm_mon)
           {
               if(dt.tm_wday>=p->tm_wday)
               {
                   return 1;
               }
           }

       }
       return 0;

}

int checkSEDate(struct tm sd,struct tm ed)
{
    if(sd.tm_year<=ed.tm_year||sd.tm_mon<=ed.tm_mon||sd.tm_wday<=ed.tm_wday)
      return 1;
    else
        if(sd.tm_mon<=ed.tm_mon)
           return 1;
    else
        if(sd.tm_wday<=ed.tm_wday)
                return 1;
    else
       return 0;
}
void updateCarCount(int c_id)
{
    FILE *fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf("Sorry can not be open");
        getch();
        return ;
    }
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {
      if(C.car_id==c_id)
      {
        int x=C.car_count;
        x--;
        fseek (fp,-8,SEEK_CUR);
        fwrite(&x,sizeof(int),1,fp);
      break;

      }
    }
    fclose(fp);
}
void bookedCarDetails()
{

    clrscr();
    FILE*fp=fopen("customer.bin","rb");
    Customer_Car_Details CC;
    int i;
    int x=10;
    textcolor(BROWN);
    gotoxy(32,1);
    printf("CAR RENTE SYSTEM\n");
    for(i=0;i<=80;i++)
        {
        printf("%c",175);
        }
    gotoxy(31,5);
    printf("*BOOKED CAR DETAILS*");
    gotoxy(1,6);
    textcolor(GREEN);
    for(i=0;i<=80;i++)
    printf("%c",175);
    gotoxy(1,8);
    printf("MODEL CAR  customer NAME\tpic Up\t   Drop\t\t  S_Date\tE_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=0;i<=80;i++)
        printf("%c",175);
    textcolor(BROWN);
    while(fread(&CC,sizeof( Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,x);
        printf("%d",CC.Car_id);
        CC.Car_id++;
        gotoxy(13,x);
        printf("%s",CC.cust_name);
        gotoxy(33,x);
        printf("%s",CC.pick);
        gotoxy(44,x);
        printf("%s",CC.drop);
        gotoxy(59,x);
        printf("%d/%d/%d",CC.sd.tm_wday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(70,x);
        printf("%d/%d/%d",CC.ed.tm_wday,CC.ed.tm_mon,CC.ed.tm_year);
    x++;
    }
    fclose(fp);
    getch();
}
char*getCarName(int c_id)
{
    FILE *fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("SORRY! FILE CANNOT BE OPENED!");
        return NULL;
    }
    static Car C;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_id==c_id)
            break;
    }
    fclose(fp);
    return C.car_name;
}
void availCarDetails()
{
     FILE*fp=fopen("car.bin","rb");
     Car C;
     int i;
     textcolor(BROWN);
     gotoxy(32,1);
     printf("CAR RENTEL SYSTEM\n");
     textcolor(LIGHTGREEN);
     gotoxy(1,2);
     for(i=0;i<=80;i++)
    {
        printf("%c",175);
    }
     gotoxy(32,5);
     textcolor(BROWN);
     printf("* AVAILABLE CAR DETAILS *");

     gotoxy(1,7);
     textcolor(LIGHTGREEN);
     for(i=0;i<=80;i++)
        {
        printf("%c",175);
        }
        if(fp==NULL)
        {
            gotoxy(32,8);
            textcolor(LIGHTRED);
            printf("SORRY FILE CAN NOT BE OPENED");
            getch();
            return;
        }
        gotoxy(1,8);
        printf("CAR ID\t\t  Model\t\tCapacity\t\tAvailable\tprice/Day");
        gotoxy(1,9);
        for(i=1;i<=80;i++)
        {
            printf("%c",175);
        }
        int row=10;
        textcolor(BROWN);
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_count>0)
            {
                gotoxy(2,row);
                printf("%d",C.car_id);
                gotoxy(19,row);
                printf("%s",C.car_name);
                gotoxy(35,row);
                printf("%d",C.capacity);
                gotoxy(57,row);
                printf("%d",C.car_count);
                gotoxy(74,row);
                printf("%d",C.price);
                row++;
        }
        }
 fclose(fp);
}
int returnCar()
{
    int i,a;
    char str[30];
    clrscr();
    gotoxy(32,1);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
    textcolor(BROWN);
    for(i=0;i<=80;i++)
    {
        printf("%c",175);
    }
    gotoxy(1,15);
    textcolor(BROWN);
    for(i=0;i<=80;i++)
    {
        printf("%c",174);
    }
    gotoxy(65,4);
    textcolor(LIGHTGRAY);
    printf("Press 0 to EXIT");
    textcolor(LIGHTCYAN);
    gotoxy(25,5);
    printf("Enter Customer name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(str,30,stdin);
    char *pos;
    pos=strchr(str,'\n');
    if(pos!=NULL)
        *pos='\0';
    if(strcmp(str,"0")==0)
        return -1;
    gotoxy(25,7);
    textcolor(LIGHTCYAN);
    printf("Enter Car id:");
    textcolor(WHITE);
    int c_id;
    scanf("%d",&c_id);
    if(c_id==0)
        return -1;
        struct tm s;
        gotoxy(25,9);
        textcolor(LIGHTCYAN);
        int m;
        m=printf("Enter Date when you want to car return:");
        while(1)
         {
            textcolor(WHITE);
            scanf("%d %d %d",&s.tm_wday,&s.tm_mon,&s.tm_year);
            int a=isValidDate(s);
            if(a==0)
             {
               textcolor(LIGHTRED);
               gotoxy(32,19);
               printf("Invalid Date");
               getch();
               gotoxy(32,19);
               printf("\t\t\t\t");
               gotoxy(25+m,9);
               printf("\t\t\t\t");
               gotoxy(25+m,9);
             }
             else
                break;
         }
    Customer_Car_Details cc;
    FILE *fp1=fopen("Customer.bin","rb");
    FILE *fp3=fopen("temp.bin","wb");

      if(fp1==NULL)
      {
          textcolor(LIGHTRED);
          gotoxy(32,19);
          printf("Sorry file Not open Customer Record Available");
          return -2;
      }
      int flag=0;
    while(fread(&cc,sizeof(cc),1,fp1)==1)
    {
        if(cc.Car_id==c_id)
        {
            if(strcmp(str,cc.cust_name)==0)
               {
                   flag=1;
               }

        }
        else
        {
           fwrite(&cc,sizeof(cc),1,fp3);
        }
    }
    fclose(fp1);
    fclose(fp3);
    FILE *fp2=fopen("car.bin","rb+");
    Car c;
    int w=0;
   if(flag==0)
   {
      remove("temp.bin");
   }
   else
   {
       remove("Customer.bin");
       rename("temp.bin","Customer.bin");

       while(fread(&c,sizeof(c),1,fp2)==1)
       {
           if(c.car_id!=c_id)
           {
                w++;
           }
           else
            {
                   int x=c.car_count;
                   x++;
                   fseek(fp2,-8,SEEK_CUR);
                   fwrite(&x,sizeof(int),1,fp2);
                   break;

            }
       }
   }
        fclose(fp2);
          if(w!=0)
          {
              clrscr();
              printf("Car id not Matched");
              return 0;
          }
           gotoxy(32,25);
           textcolor(BROWN);
           printf("Return car successfully");
          getch();
         return-1;
   }

/*int returnCar()
{
    int i,a;
    char str[30];
    clrscr();
    gotoxy(32,1);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
    textcolor(BROWN);
    for(i=0;i<=79;i++)
    {
        printf("%c",175);
    }
    gotoxy(1,15);
    textcolor(BROWN);
    for(i=0;i<=79;i++)
    {
        printf("%c",174);
    }
    gotoxy(65,4);
    textcolor(LIGHTCYAN);
    printf("Press 0 to EXIT");
    textcolor(CYAN);
    gotoxy(25,5);
    printf("Enter Customer name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(str,30,stdin);
    char *pos;
    pos=strchr(str,'\n');
    if(pos!=NULL)
        *pos='\0';
    if(strcmp(str,"0")==0)
        return -1;
    gotoxy(25,7);
    textcolor(CYAN);
    printf("Enter Car id:");
    textcolor(WHITE);
    int c_id;
    scanf("%d",&c_id);
    if(c_id==0)
        return -1;
        struct tm s;
        gotoxy(25,9);
        textcolor(CYAN);
        int m;
        m=printf("Enter Date when you want to car return:");
        while(1)
         {
            textcolor(WHITE);
            scanf("%d %d %d",&s.tm_wday,&s.tm_mon,&s.tm_year);
            int a=isValidDate(s);
            if(a==0)
             {
               textcolor(LIGHTRED);
               gotoxy(32,19);
               printf("Invalid Date");
               getch();
               gotoxy(32,19);
               printf("\t\t\t\t");
               gotoxy(25+m,9);
               printf("\t\t\t\t");
               gotoxy(25+m,9);
             }
             else
                break;
         }
    Customer_Car_Details cc;
    FILE *fp1=fopen("Customer.bin","rb");
      if(fp1==1)
      {
          textcolor(LIGHTRED);
          gotoxy(32,19);
          printf("Sorry file Not open Customer Record Available");
          return -2;
      }
      int flag=0;
    while(fread(&cc,sizeof(cc),1,fp1)==1)
    {
        if(cc.Car_id==c_id)
        {
              if(strcmp(str,cc.cust_name)==0)
            {
               flag=1;
               break;
            }
        }
    }
    int w=0;
    fclose(fp1);
    FILE*fp2=fopen("car.bin","rb");
    FILE *fp3=fopen("temp.bin","wb");
    Car c;
   if(flag==0)
   {
      textcolor(LIGHTRED);
      gotoxy(32,19);
      printf("Sorry No Customer details Match for Given Data");
      return 0;
   }
   else
   {
      /* textcolor(BROWN);
       gotoxy(32,19);
       printf("Record Match");*/
  /*     while(fread(&c,sizeof(c),1,fp2)==1)
       {
           if(c.car_id!=c_id)
           {
               fwrite(&c,sizeof(c),1,fp3);
           }
           else
            {
                 c.car_count++;
                 fwrite(&c,sizeof(c),1,fp3);
                 w++;
            }
       }
   }
       if(w==0)
       {
           remove("temp.bin");
           gotoxy(32,19);
           textcolor(LIGHTRED);
           printf("Sorry Given id is not present");
           return 1;
       }

       else
       {
           remove("car.bin");
           rename("temp.bin","car.bin");
           gotoxy(32,22);
           textcolor(BROWN);
           printf("Updated car successfully");
         return 3;
       }
    fclose(fp2);
    fclose(fp3);
   }*/








