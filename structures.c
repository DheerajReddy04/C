/*
// structures- values to variables and scaning
// imp-the code will not work if more than one variable are on the same line in a structure ex: int m,m1 won't work edit: it does work,idk why i said that
#include <stdio.h>
struct book {
    int math;
    int eng;
    int pps;
    char bookname[20];
    float price;
}b1 = {45,54};
void main() {
    printf("HELLO");
    scanf("%d %s %f",&b1.pps,b1.bookname,&b1.price);
    printf("%d\n%d\n%d\n%s\n%f\n",b1.math,b1.eng,b1.pps,b1.bookname,b1.price);
}


// A current bill program to understand the concept better
#include <stdio.h>
void billCalculation(int);
struct electricity{
    char user[50];
    float units;
    float bill;
}e;
void main() {
    printf("Enter the user's name:\n");
    scanf("%s",e.user);
    printf("Enter the number of units consumed by the user:\n");
    scanf("%f",&e.units);
    billCalculation(e.units);
}
void billCalculation(int units) {
    int rpu;
    if(units<100) {
        rpu = 10;
    }
    else if(units>100 && units<=200) {
        rpu = 15;
    }
    else if(units > 200 && units <=300) {
        rpu = 20;
    }
    else rpu = 25;
    e.bill=e.units*rpu;
    printf("The current bill is %f ",e.bill);
    
}

//Array of structure example

#include <stdio.h>
struct marks {
    char name[10];
    int math;
    int eng;
}m[5];
void main() {
    int i;
    printf("Enter the name,math marks and english marks of the students respectively:\n");
    for(i=0; i<5;i++) {
        scanf("%s",m[i].name);
        scanf("%d",&m[i].math);
        scanf("%d",&m[i].eng);
    }
    for(i=0; i<5;i++) {
        printf("The name of the student is %s.\n",m[i].name);
        printf("He/she scored %d in math and ",m[i].math);
        printf("%d in english.\n",m[i].eng);
    }
}

// Nested structure
#include <stdio.h>
struct name {
    char name[20];
    struct marks
    {
        int math;
        int english;
    }m;
    float total;
};
void main() {
    struct name n;
    scanf("%s%d%d%f",n.name,&n.m.math,&n.m.english,&n.total);
    printf("The name of the student is %s.\nHe secured %d marks in Math and %d marks in English. His total is %f",n.name,n.m.math,n.m.english,n.total);
}

//Passing structure as an argument 
// Note- Always declare the structure first before declaring a function that will use the structure.

#include<stdio.h>
struct employee{
    char name[20];
    int age;
    int salary;
}e;
void func(struct employee);
void main(){
    scanf("%s%d%d",e.name,&e.age,&e.salary);
    func(e);
}
void func(struct employee e1) {
    printf("Name:%s\nAge:%d\nSalary:%d\n",e1.name,e1.age,e1.salary);
}

// typedef - an alias for a datatype

#include <stdio.h>
typedef struct example
{
    int something, age;
    char name[20];
}e;

void main() {
    e ex,exp;
    scanf("%d%d%s",&ex.something,&ex.age,exp.name);
    printf("something is %d and age is %d Name is %s", ex.something,ex.age,exp.name);

}

//Union--only the last variable will be properly diaplayed and the other variables produce garbage valuess

#include <stdio.h>
#include <string.h>
union example
{
    int age;
    int marks;
    char name[50];
};
struct something
{
    int age;
    int marks;
    char name[50];
}e1;
void  main() {
    int len, len1;
    union example e;
    scanf("%d%d%s",&e.age,&e.marks,e.name);
    len = sizeof(e);  //sizeof(union example)
    len1 = sizeof(e1);
    printf("age is %d, marks is %d, name is %s,size of the union is %d,size of the structure is %d",e.age,e.marks,e.name,len,len1);
}

//structure within union
// note--> the variables inside the structure in union are correct but the variables inside the union output the last assigned value 
//here f=4.000000,y=4.000000
#include <stdio.h>
union point {
    struct {
        int x;
        int y;
    }value;
    float f;
    float y;
}po;
void main() {
    po.value.x = 3;
    po.value.y = 4;
    printf("x= %d, y= %d\n",po.value.x,po.value.y);
    po.f=3.14;
    po.y=4;
    printf("f=%f\n",po.f);
    printf("y= %f\n",po.y);
}

*/

/*
// union within structure
//note--> the values of structure are outputed correctly while the variables inside the union in structure return the last updated values
//here x=4,y=4
#include <stdio.h>
struct point {
    union {
        int x;
        int y;
    }value;
    float f;
    float y;
}po;
void main() {
    po.value.x = 3;
    po.value.y = 4;
    printf("x= %d, y= %d\n",po.value.x,po.value.y);
    po.f=3.14;
    po.y=4;
    printf("f=%f\n",po.f);
    printf("y= %f\n",po.y);
}
*/

//program that uses array of structures as an arguments to functions
/*
#include <stdio.h>
#include <string.h>

// Define the structure to represent a student
struct Student {
    char name[50];
    int age;
};

// Function to add students to the array of structures
void addStudents(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &students[i].age);
    }
}

// Function to display the students' information
void displayStudents(struct Student students[], int numStudents) {
    printf("\nStudent Information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Age: %d\n", students[i].name, students[i].age);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Create an array of structures to hold the student information
    struct Student students[numStudents];

    // Call the function to add students to the array of structures
    addStudents(students, numStudents);

    // Call the function to display the students' information
    displayStudents(students, numStudents);

    return 0;
}
*/

/*
// program to allocate memory to a structure using malloc
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[100];
    int age;
    float height;
};

int main() {
    int numStudents = 3;
    struct Student * ptr;
    ptr = (struct Student *)malloc(numStudents * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    printf("Enter details of %d students:\n", numStudents);
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", ptr[i].name);

        printf("Age: ");
        scanf("%d", &ptr[i].age);

        printf("Height: ");
        scanf("%f", &ptr[i].height);

        printf("\n");
    }

    printf("Details of %d students:\n", numStudents);
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", ptr[i].name);
        printf("Age: %d\n", ptr[i].age);
        printf("Height: %.2f\n\n", ptr[i].height);
    }

    free(ptr);

    return 0;
}
*/
