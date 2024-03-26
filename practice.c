//program to prAn employee can apply for a loan at the beginning of every six months, but he/she will be sanctioned the amount according to the following company rules: 
//Rule 1 : An employee cannot enjoy more than two loans at any point of time.
//Rule 2 : Maximum permissible total loan is limited to Rs.50,000
//Rule 3 : If there is any previous dues pending that amount would be deducted and the balance only will be given as loan.
//Write a program to read the values of the previous two loans got and process the new loan application and sanction the loan according to the eligibility.

/*
#include <stdio.h>
void main() {
    int loan1, loan2,loanreq;
    scanf("%d\t%d",&loan1,&loan2);
    scanf("%d",&loanreq);
    printf("%d %d\n",loan1,loan2);
    printf("%d\n",loanreq);
    if(loan1 > 0 && loan2 > 0)
    printf("0");
    if(loan1 == 0  || loan2 == 0) {
        if(loan1 == 0) {
            if(loanreq <= (50000-loan2))
            printf("%d",loanreq);
            else
            printf("%d",50000-loan2);
        }
        if(loan2 == 0) {
            if(loanreq <= (50000-loan1))
            printf("%d",loanreq);
            else
            printf("%d",50000-loan1);
        }
    }
}
*/

// if it is vowel, consonant, number, special character
/*
#include <stdio.h>
#include <ctype.h>
void main() {
    char ch;
    scanf("%c",&ch);
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch =='E' || ch == 'I' || ch == 'O' || ch == 'U')
        printf("1");
        else
        printf("2");
    }
    else if(isdigit(ch)) {
        printf("-1");
    }
    else
    printf("0");
}
*/

/*
#include <stdio.h>
int main() {
    int x;
    x = -3+4*5-6;
    printf("x = %d; ",x);
    x = 3+4%5-6;
    printf("x = %d; ",x);
    x = -3*4%-6/5;
    printf("x = %d; ",x);
    x = (7+6)%5/2;
    printf("x = %d; ",x);
}
*/

/*
#include <stdio.h>
int main() {
    int x,y,z;
    x = 2; y = 1,z = 0;
    x = x && y || z;
    printf("x = %d; ",x);
    printf("x || ! y && z = %d; ", x || ! y && z );
    x = y = 1;
    z = x++ - 1;
    printf("x = %d, z = %d; ", x, z);
    z = z + -x++ + ++ y;
    printf("x = %d, z = %d; ", x, z);
}
*/

//Guess the number game
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0; 

int getGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    count++;
    return guess;
}

void evaluateGuess(int guess, int target) {
    if (guess > target) {
        printf("Too high! Try again.\n");
    } else if (guess < target) {
        printf("Too low! Try again.\n");
    } else {
        printf("Congratulations! You guessed the number.\n");
        printf("Total guesses: %d\n", count);
        exit(0);
    }
}

int main() {
    int lower, upper, target, guess;
    printf("Enter lower bound: ");
    scanf("%d", &lower);
    printf("Enter upper bound: ");
    scanf("%d", &upper);
    if (lower >= upper) {
        printf("Please enter appropriate values (lower should be less than upper).\n");
        return 1; 
    }
    srand(time(NULL));
    target = lower + rand() % (upper - lower + 1);
    while (1) { // Continue until the user guesses the correct number
        guess = getGuess();
        evaluateGuess(guess, target);
    }
    return 0;
}
*/

//Bingo single line win




/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBingoCard(int card[3][3]) {
    int numSet[30] = {0}; 
    int columnRanges[3] = {1, 11, 21};
    for (int col = 0; col < 3; col++) {
        for (int row = 0; row < 3; row++) {
            int rangeStart = columnRanges[col];
            int rangeEnd = columnRanges[col] + 9;
            int num;
            do {
                num = rangeStart + rand() % 10; 
            } while (numSet[num - 1] == 1);
            card[row][col] = num;
            numSet[num - 1] = 1;
        }
    }
}

void displayBingoCard(int card[3][3], int calledNumbers[30]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int number = card[row][col];
            char symbol = ' ';
            if (calledNumbers[number - 1] == 1) {
                symbol = '*'; 
            }
            printf("%c%d%c\t", symbol, number, symbol);
        }
        printf("\n");
    }
    printf("\n");
}

int checkSingleLineWin(int card[3][3], int calledNumbers[30]) {
    for (int row = 0; row < 3; row++) {
        int rowComplete = 1;
        for (int col = 0; col < 3; col++) {
            if (calledNumbers[card[row][col] - 1] != 1) {
                rowComplete = 0;
                break;
            }
        }
        if (rowComplete) {
            return 1; 
        }
    }
    for (int col = 0; col < 3; col++) {
        int colComplete = 1;
        for (int row = 0; row < 3; row++) {
            if (calledNumbers[card[row][col] - 1] != 1) {
                colComplete = 0;
                break;
            }
        }
        if (colComplete) {
            return 1;
        }
    }
    if (calledNumbers[card[0][0] - 1] == 1 && calledNumbers[card[1][1] - 1] == 1 && calledNumbers[card[2][2] - 1] == 1) {
        return 1;
    }
    if (calledNumbers[card[0][2] - 1] == 1 && calledNumbers[card[1][1] - 1] == 1 && calledNumbers[card[2][0] - 1] == 1) {
        return 1; 
    }
    return 0; 
}

int generateRandomCall(int calledNumbers[30]) {
    int num;
    do {
        num = 1 + rand() % 30; 
    } while (calledNumbers[num - 1] == 1); 
    calledNumbers[num - 1] = 1; 
    return num;
}

int main() {
    int bingoCard[3][3];
    int calledNumbers[30] = {0}; 
    srand(time(NULL)); 
    generateBingoCard(bingoCard);
    printf("Welcome to Bingo!\n");
    displayBingoCard(bingoCard, calledNumbers);
    while (1) { 
        int calledNumber = generateRandomCall(calledNumbers);
        printf("Called number: %d\n", calledNumber);
        displayBingoCard(bingoCard, calledNumbers);
        if (checkSingleLineWin(bingoCard, calledNumbers)) {
            printf("Congratulations! You have a single-line Bingo!\n");
            break;
        }
        char choice;
        printf("Enter 'Q' to quit or any other key to continue: ");
        scanf(" %c", &choice);
        if (choice == 'Q' || choice == 'q') {
            break; 
        }
    }
    printf("Thanks for playing Bingo!\n");
    return 0;
}

*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    clock_t start, end;
    double execution_time;
    int arr[10];
    start = clock();
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101; // Generate random numbers between 1 and 100
    }
    int moves = 0;
    printf("Welcome to the Bubble Sort Game!\n");
    while (!isSorted(arr, 10)) {
        printf("Current Array: ");
        printArray(arr, 10);
        int index1, index2;
        printf("Enter indices to swap (e.g., 2 3): ");
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= 10 || index2 < 0 || index2 >= 10) {
            printf("Invalid indices. Try again.\n");
            continue;
        }
        swap(arr, index1, index2);
        printf("Moves: %d\n",++moves);
    }
    printf("Congratulations! You sorted the array in %d moves.\n", moves);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds\n", execution_time);
    return 0;
}

