#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Song {
    char title[50];
    char artist[50];
    struct Song* next;
};

void addSong(struct Song** playlist, const char* title, const char* artist) {   
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = *playlist;
    *playlist = newSong;
    printf("Song '%s' by %s added to the playlist.\n", title, artist);
}

void removeSong(struct Song** playlist, const char* title) {
    struct Song* current = *playlist;
    struct Song* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                *playlist = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Song '%s' removed from the playlist.\n", title);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Song '%s' not found in the playlist.\n", title);
}

void shufflePlaylist(struct Song** playlist) {
    int count = 0;
    struct Song* current = *playlist;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    struct Song* songs[count];
    current = *playlist;
    for (int i = 0; i < count; i++) {
        songs[i] = current;
        current = current->next;
    }
    srand(time(NULL));
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Song* temp = songs[i];
        songs[i] = songs[j];
        songs[j] = temp;
    }
    *playlist = songs[0];
    current = *playlist;
    for (int i = 1; i < count; i++) {
        current->next = songs[i];
        current = current->next;
    }
    current->next = NULL;
    printf("Playlist shuffled.\n");
}

void displayPlaylist(struct Song* playlist) {
    printf("\nCurrent Playlist:\n");
    while (playlist != NULL) {
        printf("Title: %s | Artist: %s\n", playlist->title, playlist->artist);
        playlist = playlist->next;
    }
    printf("\n");
}

void freePlaylist(struct Song** playlist) {
    struct Song* current = *playlist;
    struct Song* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *playlist = NULL;
}

int main() {
    struct Song* playlist = NULL;
    int choice;
    char title[50], artist[50];
    do {
        printf("Music Playlist Manager\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Shuffle Playlist\n");
        printf("4. Display Playlist\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter song title: ");
                scanf("%s", title);
                printf("Enter artist name: ");
                scanf("%s", artist);
                addSong(&playlist, title, artist);
                break;
            case 2:
                printf("Enter the title of the song to remove: ");
                scanf("%s", title);
                removeSong(&playlist, title);
                break;
            case 3:
                shufflePlaylist(&playlist);
                break;
            case 4:
                displayPlaylist(playlist);
                break;
            case 5:
                freePlaylist(&playlist);
                printf("Exiting the Music Playlist Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}