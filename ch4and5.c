//Stack, Queue, Bubble sort, Selection sort, Insertion sort, Quick sort, Linera search, Binary search

//Linear Search
/*
#include <stdio.h>
int lsearch(int[],int,int);
void main() {
    int a[100],k,n,x;
    scanf("%d%d",&k,&n);
    for(int i=0; i<n;i++)
    scanf("%d", &a[i]);
    x = lsearch(a,k,n);
    if(x == -1)
    printf("element not found\n");
    else
    printf("Element found at %d position\n",x);
}
int lsearch(int a[],int k, int n) {
    for(int i = 0; i<n;i++) {
        if(a[i] == k)
        return i+1;
    }
    return(-1);
}
*/

//Binary Search
/*
#include <stdio.h>
int bsearch(int[],int,int);
void main() {
    int a[100],k,n,x;
    scanf("%d%d",&k,&n);
    for(int i = 0;i<n;i++)
    scanf("%d",&a[i]);
    x = bsearch(a,k,n);
    if(x == -1)
    printf("Element not found\n");
    else 
    printf("element found at %d position\n",x);
}
int bsearch(int a[], int k, int n) {
    int beg = 0, end = n - 1, mid;
    while(beg <= end) {
        mid = (beg + end) / 2;
        if(k == a[mid])
        return mid+1;
        else if(k > a[mid])
        beg = mid + 1;
        else
        end = mid - 1;
    }
    return -1;
}
*/


// bubble sort
/*
#include <stdio.h>
void bubblesort(int[],int);
void display(int[],int);
void main() {
    int a[100],n;
    printf("Number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    bubblesort(a,n);
    printf("Sorted array in ascending order\n");
    display(a,n);
} 
void bubblesort(int a[], int n) {
    int temp;
    for(int i=0; i < n-1; i++) {
        int c = 0;
        for(int j=0; j< n - i -1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                c++;
            }
        }
        if(c == 0) {
            break;
        }
    }
}
void display(int a[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d\t",a[i]);
    }
}
*/
// selection sort
/*
#include <stdio.h>
void selectionsort(int[],int);
void display(int[],int);
void main() {
    int a[100],n;
    printf("Number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    selectionsort(a,n);
    printf("Sorted array in ascending order\n");
    display(a,n);
} 
void selectionsort(int a[], int n) {
    int min, temp;
    for(int i = 0;i<n; i++) {
        min = i;
        for(int j=i+1;j<n;j++) {
            if(a[j] < a[min])
            min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}   
void display(int a[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d\t",a[i]);
    }
}
*/
// Insertion sort
/*
#include <stdio.h>
void insertionsort(int[],int);
void display(int[],int);
void main() {
    int a[100],n;
    printf("Number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    insertionsort(a,n);
    printf("Sorted array in ascending order\n");
    display(a,n);
} 
void insertionsort(int a[], int n) {
    int temp,i,j;
    for(i=1; i<n;i++) {
        temp = a[i]; 
        j=i;
        while(j>0 && a[j-1] > temp) {
            a[j] = a[j-1];
            j = j-1;
        }
        a[j] = temp;
    }
}   
void display(int a[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d\t",a[i]);
    }
}
*/

//Quick sort
/*
#include<stdio.h>
void quicksort(int a[10],int first,int last);
void main(){
int a[10],i,n;
printf("Enter no of elements : ");
scanf("%d",&n);
printf("Enter %d elements : ",n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
quicksort(a,1,n);
printf("Sorted Elements are : ");
for(i=1;i<=n;i++)
printf("%3d",a[i]);
}
void quicksort(int a[10],int first,int last) {
int pivot,i,j,t;
if(first<last) {
pivot=first; 
 i=first;
 j=last;
while(i<j) {
while(a[i]<=a[pivot] && i<last)
i++;
while(a[j]>a[pivot])
j--;
if(i<j) {
t=a[i]; 
 a[i]=a[j]; 
 a[j]=t;
} 
}
t=a[pivot];
a[pivot]=a[j];
a[j]=t;
quicksort(a,first,j-1);
quicksort(a,j+1,last);
} 
}
*/

// stack implementation with array
/*
#include <stdio.h>
#include <stdlib.h>
#define size 100
struct stack {
    int list[size];
    int top;
};
void push(struct stack*, int);
int pop(struct stack*);
int peak(struct stack);
void display(struct stack);
int main() {
    struct stack s;
    s.top = -1;
    int op, x,n;
    while(1) {
        printf("Enter choice 1. Push 2. Pop 3. Top value 4. Display 0. exit\n");
        scanf("%d",&op);
        switch(op) {
            case 1 : printf("Enter element to be pushed\n");
                     scanf("%d",&x);
                     push(&s,x);
                     break;
            case 2 : n = pop(&s);
                     if(n != -1)
                     printf("The popped value is %d\n",n);
                     break;
            case 3 : n = peak(s);
                     printf("The toppest value is %d\n",n);
                     break;
            case 4 : display(s);
                     break;
            case 0 : return 0;
            default : printf("Enter a valid choice\n");
        }
    }
    return 0;
}
void push(struct stack * sp, int x) {
    if(sp->top == size -1 )
    printf("Overflow\n");
    else
    sp->list[++sp->top] = x;
}
int pop(struct stack * sp) {
    if(sp->top == -1)  {
    printf("Underflow\n");
    return -1;
    }
    else
    return(sp->list[sp->top--]);
}
int peak(struct stack s) {
    if(s.top == -1) {
    printf("No elements\n");
    return -1;
    }
    else
    return s.list[s.top];
}
void display(struct stack s) {
    if(s.top == -1)
    printf("No elements\n");
    else {
        for(int i = 0; i <= s.top;i++)
        printf("%d\t",s.list[i]);
    }
}
*/


/*
// queue implementation using array
#include <stdio.h>
#include <stdlib.h>
#define size 100
struct queue {
    int list[size];
    int front;
    int rear;
};
void enqueue(struct queue *,int);
int dequeue(struct queue *);
void display(struct queue);
int main() {
    struct queue q;
    q.front = 0;
    q.rear = -1;
    int op, x, n;
    while(1) {
        printf("Enter choice 1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d",&op);
        switch(op) {
            case 1 : printf("Enter element to be enqueued\n");
                     scanf("%d",&x);
                     enqueue(&q,x);
                     break;
            case 2 : n = dequeue(&q);
                     if(n != -1)
                     printf("Dequeued element: %d\n",n);
                     break;
            case 3 : display(q);
                     break;
            case 4 : return 0;
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}
void enqueue(struct queue * q, int x) {
    if(q->rear == size - 1)
    printf("Overflow\n");
    else
    q->list[++q->rear] = x;
}
int dequeue(struct queue * q) {
    if(q->front == q->rear)
    printf("Underflow\n");
    else
    return q->list[q->front++];
}
void display(struct queue q) {
    if(q.front > q.rear) {
        printf("No elements\n");
    }
    else {
    for(int i = q.front; i <= q.rear ; i++)
    printf("%d\t",q.list[i]);
    }
    printf("\n");
}
*/