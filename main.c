#include <stdio.h>
#include <string.h>

void displayIntro();
void displayMenu();
void move(char *direction);
void look();
void quit();

struct Room {
    char description[256];
    char exists[4][10];
};

int isPlaying = 1;

int main(void) {
    char input[100];
    char command[10];
    char argument[10];

    displayIntro();

    while(isPlaying) {
        displayMenu();
        printf("> ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) {
            printf("You didn't enter a command. Try again.\n");
            continue;
        }

        sscanf(input, "%s %s", command, argument);

        if (strcmp(command, "move") == 0) {
            move(argument);
        } else if(strcmp(command, "look") == 0) {
            look();
        } else if (strcmp(command, "quit") == 0) {
            quit();
        } else {
            printf("Invalid command. Try 'move', 'look' or 'quit'.\n");
        }
    }

    return 0;
}

void displayIntro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You fin yourself in a mysterious room.\n");
    printf("Your objective is to explore the room and survive.\n");
}

void displayMenu() {
    printf("\nCommands:\n");
    printf("move <direction> - Move in a direction (north, south, east, west).\n");
    printf("look             - Look around to get information about your surroundings.\n");
    printf("quit             - Quit the game.\n");
}

int playerPosition = 0;

void move(char *direction) {
    if (strcmp(direction, "north") == 0) {
        printf("You move north.\n");
    } else if (strcmp(direction, "south") == 0) {
        printf("You move south.\n");
    } else if (strcmp(direction, "east") == 0) {
        printf("You move east.\n");
    } else if (strcmp(direction, "west") == 0) {
        printf("You move west.\n");
    } else {
        printf("Unknown direction. Try 'north', 'south', 'east', or 'west'.\n");
    }
}

void look() {
    printf("You are standing in an empty room. There's a door in each direction.\n");
}

void quit() {
    printf("Thanks for playing! Goodbye.\n");
    isPlaying = 0;
}