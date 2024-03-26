#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main() {
    int choice = 0;

    while (choice != 9) {
        printf("\n\n****Main Menu****\n");
        printf("Choose one option from the following list...\n");
        printf("===============================================\n");
        printf("1. Insert in the beginning\n2. Insert at the last\n3. Insert at any random location\n");
        printf("4. Delete from the beginning\n5. Delete from the last\n6. Delete node after specified location\n");
        printf("7. Search for an element\n8. Show\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                last_delete();
                break;
            case 6:
                random_delete();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}

void beginsert() {
    struct node* ptr;
    int item;

    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = head;
    head = ptr;

    printf("\nNode inserted.\n");
}

void lastinsert() {
    struct node* ptr, * temp;
    int item;

    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    printf("\nNode inserted.\n");
}

void randominsert() {
    struct node* ptr, * temp;
    int item, loc, i;

    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;

    printf("\nEnter the location after which you want to insert: ");
    scanf("%d", &loc);

    temp = head;
    for (i = 1; i < loc; i++) {
        if (temp == NULL) {
            printf("\nCan't insert.\n");
            return;
        }
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    printf("\nNode inserted.\n");
}

void begin_delete() {
    struct node* ptr;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    ptr = head;
    head = head->next;
    free(ptr);

    printf("\nNode deleted from the beginning.\n");
}

void last_delete() {
    struct node* ptr, * prev;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nOnly node of the list deleted.\n");
        return;
    }

    ptr = head;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;
    free(ptr);

    printf("\nDeleted node from the last.\n");
}

void random_delete() {
    struct node* ptr, * prev;
    int loc, i;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nEnter the location of the node after which you want to perform deletion: ");
    scanf("%d", &loc);

    ptr = head;
    for (i = 1; i < loc; i++) {
        prev = ptr;
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("\nCan't delete.\n");
            return;
        }
    }

    prev->next = ptr->next;
    free(ptr);

    printf("\nDeleted node at location %d.\n", loc);
}

void search() {
    struct node* ptr;
    int item, pos = 0, flag = 0;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nEnter the item you want to search: ");
    scanf("%d", &item);

    ptr = head;
    while (ptr != NULL) {
        pos++;
        if (ptr->data == item) {
            printf("Item found at location %d.\n", pos);
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (flag == 0) {
        printf("Item not found.\n");
    }
}

void display() {
    struct node* ptr;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    ptr = head;
    printf("\nPrinting values:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}