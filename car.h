#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
struct User
{
    char userid[20];
    char pwd[20];
    char name[20];
};
struct Car
{
    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;

};
typedef struct Customer_Car_Details
{
    int Car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
}Customer_Car_Details;
typedef struct User User;
typedef struct Car Car;
void addAdmin();
User*getinput();
int chekUserExist(User,char*);
int adminMenu();
void addEmpolyee();
void viewEmpolyee();
void addCarDetails();
void showCarDetails();
int deletEmp();
int deleteCarModel();
int empMenu();
int selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetails();
 int rentValidDate(struct tm);
 char*getCarName(int);
 int rentCar();
 void availCarDetails();
int checkSEDate(struct tm,struct tm);
int returnCar();
#endif // CAR_H_INCLUDED
