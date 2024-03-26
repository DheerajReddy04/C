// swapping numbers using call by reference
/*
#include <stdio.h>
void swap(int *,int *);
void main() {
    int x,y;
    scanf("%d%d",&x,&y);
    swap(&x,&y);
    printf("%d\n%d",x,y);
}
void swap(int * x,int * y) {
    int c;
    c = *x;
    *x = *y;
    *y = c;
}
*/

// usuage of %u, %p, %x and %d with pointers
/*
#include <stdio.h>
void main() {
    int *y,x=5;
    y = &x;
    printf("%x\n",y); //unsigned hexadecimal integer
    printf("%p\n",y); //pointer address
    printf("%u\n",y); //decimal integer
    printf("%d\n",y); //gives address as the output
}
*/

//pointer to pointer
/*
#include <stdio.h>
void main() {
    int a =10, p,*p1;
    p = &a;
    p1 = &p;
    printf("%d\n",a);
    printf("%d\n",*p);
    printf("%d\n",**p1);
}
*/

// pointer to array/ different ways to get values
/*
#include <stdio.h>
void main() {
    int a[5], *p, i;
    p = a;
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    for(i=0;i<5;i++)
    printf("%d",a[i]);
    printf("\n");
    for(i=0;i<5;i++)
    printf("%d",p[i]);
    printf("\n");
    for(i=0;i<5;i++)
    printf("%d",*(a+i));
    printf("\n");
    for(i=0;i<5;i++)
    printf("%d",*(p+i));
    printf("\n");
    for(i=0;i<5;i++)
    printf("%d",*(i+a));
    printf("\n");
    for(i=0;i<5;i++)
    printf("%d",*(i+p));
    printf("\n");    
}
*/

// pointer to structure
/*
#include <stdio.h>
struct example {
    int no;
    int age;
};
void main() {
    struct example e,*e1;
    e1 =&e;
    scanf("%d%d",&e1->no,&e1->age);
    printf("%d%d\n",e1->no,e1->age);
    scanf("%d%d",&e.no,&e.age);
    printf("%d%d",e.no,e.age);
}
*/

// program to find an element in an array using pointers
/*
#include <stdio.h>
#include <stdlib.h>
void main() {
    int *p,k,n=5,i;
    p = (int *)malloc(n*sizeof(int));
    scanf("%d",&k);
    for(i=0;i<n;i++)
    scanf("%d",(p+i));
    for(i = 0;i<n;i++) {
        if(k == p[i])
        printf("Element found: %d\n",p[i]);
        
    }
}
*/

#include <stdio.h>
void main() {
int n;
printf("Enter number of elements: ");
scanf("%d", &n);
int list[n];
for (int i = 0; i < n; i++) {
int var;
scanf("%d", &var);
list[i] = var;
}
printf("The numbers above 100 in the given list are:\n");
for (int i = 0; i < n; i++) {
if (list[i] >= 100) {
printf("%d\n", list[i]);
}
}
}
