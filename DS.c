/*
// Stack using array
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
// Stack using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

void push();
void pop();
void display();

void main() {
    while(1) {
        int choice;
        printf("1.Push \n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: "Enter a vlaid choice.\n";
        }
    }
}

void push() {
    int x;
    printf("Enter the item to be pushed.\n");
    scanf("%d",&x);
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if(top == NULL)
    newnode->next = NULL;
    else
    newnode->next=top;
    top = newnode;
    printf("Item pushed.\n");
}

void pop() {
    if(top == NULL) {
        printf("Underflow!\n");
    }
    else {
        struct node *temp = top;
        printf("Deleted node: %d\n",temp->data);
        top = temp->next;
        free(temp);
    }
}

void display() {
    if(top == NULL) {
        printf("No elements to display.\n");
    }
    else{
        struct node *temp = top;
        while(temp->next != NULL) {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}
*/



/*
//Queue with array
#include <stdio.h>
#include <stdlib.h>
#define size 100

struct queue {
    int list[size];
    int front;
    int rear;
};

void enqueue(struct queue *, int);
int dequeue(struct queue *);
void display(struct queue);

int main() {
    struct queue q;
    q.front = 0;
    q.rear = -1;
    int op, x, n;
    while(1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice\n");
        scanf("%d",&op);
        switch(op){
            case 1: printf("Enter the item to be enqueued\n");
            scanf("%d",&x);
            enqueue(&q, x);
            break;
            case 2: n=dequeue(&q);
            if(n != -1) {
                printf("The Dequeued item is %d\n",n);
            }
            break;
            case 3: display(q);
            break;
            case 4: return 0;
            break;
            default: printf("Enter a valid number.\n");
        }
    }
    return 0;
}

void enqueue(struct queue * q, int x) {
    if(q->rear == size-1) {
        printf("Overflow!\n");
    }
    else{
        q->list[++q->rear] = x;
        printf("Item succesfully enqueued!\n");
    }
}

int dequeue(struct queue * q) {
    if(q->front > q->rear) {
        printf("Underflow!\n");
        return -1;
    }
    else{
        return q->list[q->front++];
    }
}

void display(struct queue q) {
    int i;
    if(q.front > q.rear) {
        printf("No elements in list!\n");
    }
    else{
        for(i = q.front;i<q.rear;i++) {
            printf("%d\t",q.list[i]);
        }
        printf("\n");
    }
} 
*/


/*
//Queue with Linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enqueue();
void dequeue();
void display();

int main() {
    while(1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice.\n");
        int op;
        scanf("%d",&op);
        switch(op) {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: return 0;
            default: printf("Enter a valid choice!\n");
        }
    }
    return 0;
}

void enqueue() {
    int x;
    printf("Enter the value to be enqueued.\n");
    scanf("%d",&x);
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(front == NULL)
    front = rear = newnode;
    else{
        rear->next = newnode;
        rear = newnode;
    }
    printf("Insertion is successful!!\n");
}

void dequeue() {
    struct node *temp;
    temp = front;
    front = front->next;
    printf("Deleted Item is %d\n",temp->data);
    free(temp);
}

void display() {
    struct node *temp;
    temp = front;
    while(temp->next != NULL) {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
*/



/*
// Infix to Postfix Conversion
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1)
    return -1;
    else
    return stack[top--];
}

int priority(char x) {
    if(x == '(')
    return 0;
    if(x == '+' || x == '-')
    return 1;
    if(x == '*' || x == '/')
    return 2;
    return 0;
}

int main(){
    char exp[100];
    char *e, x;
    printf("Enter the Infix Expression: \n");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0') {
        if(isalnum(*e))
        printf("%c ",*e);
        else if(*e == '(')
        push(*e);
        else if(*e == ')'){
            while((x = pop()) != '(')
            printf("%c ",x);
        }
        else {
            while(priority(stack[top]) >= priority(*e))
            printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1) {
        printf("%c ",pop());
    }
    return 0;
}
*/




/*
//Evaluation of Postfix Expression
#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100],*e;
    int x,n1,n2,n3,num;
    printf("Enter the Postfix Expresion: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0') {
        if(isdigit(*e)) {
            num = *e - 48;
            push(num);
        }
        else{
            n1 = pop();
            n2 = pop();
            switch(*e) {
                case '+' : n3 = n2+n1;
                break;
                case '-' : n3 = n2-n1;
                break;
                case '*' : n3 = n2*n1;
                break;
                case '/' : n3 = n2/n1;
                break;
            }
            push(n3);
        }
        e++;
    }
    printf("The result of the Postfix Expression %s is: %d",exp,pop());
    return 0;
}
*/



/*
//Tower of hanoi
#include <stdio.h>

void toh(int n, char rodA, char rodC, char rodB) {
    if(n == 1) {
        printf("\n Move disk 1 from %c to %c",rodA,rodC);
        return;
    }
    toh(n-1,rodA,rodB,rodC);
    printf("\n Move disk %d from %c to %c",n,rodA,rodC);
    toh(n-1,rodB,rodC,rodA);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    toh(n,'A','C','B');
    return 0;
}
*/



/*
//Parenthesis Checking
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

struct stack {
    char list[size];
    int top;
}s;

void push(char x) {
    if(s.top == (size-1)) 
    printf("Overflow!\n");
    else
    s.list[++s.top] = x;
}

void pop() {
    if(s.top == -1) 
    printf("Stack is empty!\n");
    else
    s.top = s.top-1;
}

int checkpair(char val1,char val2) {
    return ((val1 == '(' && val2 == ')') || (val1 == '[' && val2 == ']') || (val1 == '{' &&  val2 == '}'));
}

int checkbalanced(char expr[],int len) {
    for(int i = 0; i<len;i++){
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        push(expr[i]);
        else{
            if(s.top == -1)
            return 0;
            else if(checkpair(s.list[s.top],expr[i])){
                pop();
                continue;
            }
            return 0;
        }
    }
    return 1;
}

int main() {
    char exp[size];
    printf("Enter the Expression.\n");
    scanf("%s",exp);
    int len;
    s.top = -1;
    len = strlen(exp);
    checkbalanced(exp,len)? printf("Balanced\n") : printf("Not Balanced\n");
    return 0;
}
*/

#include<stdio.h>
#include<limits.h>
int heap[1000000], heapSize;
void init()
{
    heapSize = 0;
    heap[0] = -INT_MAX;
}
 
void Insert(int element) 
{
    heapSize++;
    heap[heapSize] = element; 
    int now = heapSize;
    while (heap[now / 2] > element) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}
 
int DeleteMin() 
{
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for (now = 1; now * 2 <= heapSize; now = child) {
        child = now * 2;
        if (child != heapSize && heap[child + 1] < heap[child]) {
            child++;
  }

        if (lastElement > heap[child]) {
            heap[now] = heap[child];
        } else 
        {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}
 
int main() {
    int number_of_elements;
    printf("Program to demonstrate Heap:\nEnter the number of elements: ");
    scanf("%d", &number_of_elements);
    int iter, element;
    init();
    printf("Enter the elements: ");
    for (iter = 0; iter < number_of_elements; iter++) {
        scanf("%d", &element);
        Insert(element);
    }
    for (iter = 0; iter < number_of_elements; iter++) {
        printf("%d ", DeleteMin());
    }
    printf("\n");
    return 0;
}
