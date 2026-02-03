// Write a demonstration of pass by value and pass by reference for structure.

// #include<stdio.h>

// struct student{
//     int age;
//     int id;
//     char *name;
// };

// void displayData(struct student sA)  // Pass by value
// {
//     printf("Name: %s\nAge: %d\nID: %d\n\n", sA.name, sA.age, sA.id);
// }

// void changeAge(struct student *sA, int newAge) //Pass by reference
// {
//     sA->age = newAge;
// }

// int main()
// {
//     struct student studentA = {13, 2024001, "Shimanto"};

//     displayData(studentA);
//     changeAge(&studentA, 20);
//     displayData(studentA);

//     return 0;
// }

// For 5 students, create a struct, that will store their reg, course code, marks gpa (determine it from the marks )

// Use nested structure to include the date of birth of the student.

// Change the value of an element to a structure by passing it to a function. Print the previous and the current value using the pointer.
// Create an array of stucture, populate, and print

#include<stdio.h>

struct student{
    char *name;
    int age;
    int id;
};

void changeAge(struct student *learner)
{
    learner->age = (learner->age) * 2;
}

int main()
{
    struct student student1;
    student1.name = "shanto";
    student1.age = 22;
    student1.id = 360;

    printf("Student %s 's current age is %d\n", student1.name, student1.age);
    struct student *pointer = &student1;
    changeAge(pointer);

    printf("Student %s 's age after passing is %d\n", pointer->name, pointer->age);

    struct student students[3];
    for (int i = 0; i < 3; i++)
    {
        students[i].name = "kung fu";
        students[i].age = i * 30;
        students[i].id = 111 * i;
    }

    for (int j = 0; j < 3; j++)
    {
        printf("Student: %s \n Age: %d \n ID: %d\n\n", students[j].name, students[j].age, students[j].id);
    }
        return 0;
}