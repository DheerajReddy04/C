//Memory Match Game(more like Guess game)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Card {
    int number;
    int isFaceUp;
    struct Card* next;
} Card;

void initializeGrid(Card*** grid, int size) {
    *grid = (Card**)malloc(size * sizeof(Card*));
    for (int i = 0; i < size; i++) {
        (*grid)[i] = (Card*)malloc(size * sizeof(Card));
    }
    int cardCount = size * size;
    int* numbers = (int*)malloc((cardCount / 2) * sizeof(int));
    for (int i = 0; i < cardCount / 2; i++) {
        numbers[i] = i + 1;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (*grid)[i][j].number = numbers[(i * size + j) % (cardCount / 2)];
            (*grid)[i][j].isFaceUp = 0;  
            (*grid)[i][j].next = NULL;
        }
    }
    free(numbers);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int x = rand() % size;
            int y = rand() % size;
            Card temp = (*grid)[i][j];
            (*grid)[i][j] = (*grid)[x][y];
            (*grid)[x][y] = temp;
        }
    }
}

void displayGrid(Card** grid, int size) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].isFaceUp) {
                printf("%3d ", grid[i][j].number);
            } else {
                printf("  X ");
            }
        }
        printf("\n");
    }
}

void findCoordinates(int value, int size, int* x, int* y) {
    value--; 
    *x = value / size;
    *y = value % size;
}

void flipCards(Card** grid, int size, int value1, int value2, int* pairsFound) {
    int x1, y1, x2, y2;
    findCoordinates(value1, size, &x1, &y1);
    findCoordinates(value2, size, &x2, &y2);
    if (!grid[x1][y1].isFaceUp && !grid[x2][y2].isFaceUp) {
        grid[x1][y1].isFaceUp = 1;
        grid[x2][y2].isFaceUp = 1;
        if (grid[x1][y1].number == grid[x2][y2].number) {
            printf("Match found!\n");
            (*pairsFound)++;
        } else {
            printf("No match. Turning cards face down.\n");
            grid[x1][y1].isFaceUp = 0;
            grid[x2][y2].isFaceUp = 0;
        }
    } else {
        printf("Invalid move. Cards already face up.\n");
    }
}

void deallocateGrid(Card*** grid, int size) {
    for (int i = 0; i < size; i++) {
        free((*grid)[i]);
    }
    free(*grid);
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the grid (even number): ");
    scanf("%d", &size);
    if (size % 2 != 0) {
        printf("Invalid grid size. Please enter an even number.\n");
        return 1;
    }
    Card** grid;
    initializeGrid(&grid, size);
    int pairsFound = 0;
    int totalPairs = size * size / 2;
    while (pairsFound < totalPairs) {
        displayGrid(grid, size);
        int value1, value2;
        printf("Enter the values of two cards to flip: ");
        scanf("%d %d", &value1, &value2);
        if (value1 < 1 || value1 > size * size || value2 < 1 || value2 > size * size) {
            printf("Invalid values. Please enter values within the range.\n");
            continue;
        }
        flipCards(grid, size, value1, value2, &pairsFound);
    }
    printf("Congratulations! You found all the pairs.\n");
    deallocateGrid(&grid, size);
    return 0;
}