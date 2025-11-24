#include<stdio.h> 
#include<string.h> 

struct Name
{
    char firstName[30];
    char secondName[30];
    char thirdName[30];
};

struct Address
{
    char village[30];
    char upazilla[30];
    char division[30];
    char district[30];
};

struct Student{
    struct Name studentName;
    struct Address studentAddress;
    int age;
    int roll;
    float cgpa; 
};

int main()
{
    int age;
    int height; 
    struct Student Shanto;
    strcpy(Shanto.studentName.firstName, "Nayeem");
    strcpy(Shanto.studentName.secondName, "Islam");
    strcpy(Shanto.studentName.thirdName, "Shanto"); 

    
    printf("%s", Shanto.studentName.firstName); 

    return 0; 
}