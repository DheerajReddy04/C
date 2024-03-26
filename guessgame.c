// C program to implements the above 
// memory game 
#include <conio.h> 
#include <dos.h> 
#include <stdio.h> 
#include <stdlib.h> 

// Function to generate the random 
// number at each new level 
int randomnum(long level) 
{ 
	clrscr(); 
	printf("Level %ld \n", level); 

	long num; 
	num = (rand() % 100 * level) 
		+ 1 + level * 5.2f; 

	printf("Number : %ld \n", num); 
	delay(2000 - (10 * level)); 
	clrscr(); 

	// Return the number 
	return num; 
} 

// Driver Code 
void main() 
{ 
	clrscr(); 
	long num; 
	long guessnum; 

	long level = 1; 

	long inputnum; 

	// Start the game 
	printf("Press 1 to start Game! "); 
	scanf("%ld", &inputnum); 

	// Game Starts 
	if (inputnum == 1) { 

		// Iterate until game ends 
		do { 

			// Generate a random number 
			num = randomnum(level); 

			// Get the guessed number 
			scanf("%ld", &guessnum); 
			level++; 

			// Condition for the Game 
			// Over State 
			if (guessnum != num) { 
				printf("You Failed! "); 
			} 
		} while (num == guessnum); 
	} 

	getch(); 
} 
