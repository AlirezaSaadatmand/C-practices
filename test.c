// C program to implement an interactive
// snake game
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Macros variable (HEIGHT, WIDTH)
#define HEIGHT 20
#define WIDTH 40

// Array to store the coordinates of snake
// tail (x-axis, y-axis)
int snakeTailX[100], snakeTailY[100];

// Variable to store the length of the
// snake's tail
int snakeTailLen;

// Score and signal flags
int gameover, key, score;

// Coordinates of snake's head and fruit
int x, y, fruitx, fruity;

// Function to generate the fruit
// within the boundary
void setup() {
    
    // Flag to signal the gameover
    gameover = 0;

    // Initial coordinates of the snake
    x = WIDTH / 2;
    y = HEIGHT / 2;
    
    // Initial coordinates of the fruit
    fruitx = rand() % WIDTH;
    fruity = rand() % HEIGHT;
    while (fruitx == 0)
        fruitx = rand() % WIDTH;

    while (fruity == 0)
        fruity = rand() % HEIGHT;

    // Score initialzed
    score = 0;
}

// Function to draw the game field, snake
// and fruit
void draw() {
    system("cls");
    
    // Creating top wall
    for (int i = 0; i < WIDTH + 2; i++)
        printf("-");
    printf("\n");
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {

            // Creating side walls with '#'
            if (j == 0 || j == WIDTH)
                printf("#");
            
            // Creating snake's head with 'O'
            if (i == y && j == x)
                printf("O");
            
            // Creating the sanke's food with '*'
            else if (i == fruity && j == fruitx)
                printf("*");
            
            // Creating snake's body with 'o'
            else {
                int prTail = 0;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j
                        && snakeTailY[k] == i) {
                        printf("o");
                        prTail = 1;
                    }
                }
                if (!prTail)
                    printf(" ");
            }
        }
      printf("\n");
            
    }
    
    // Creating bottom walls with '-'
    for (int i = 0; i < WIDTH + 2; i++)
        printf("-");
     printf("\n");

    // Print the score and instructions
    printf("score = %d", score);
    printf("\n");
    printf("Press W, A, S, D for movement.\n");
    printf("Press X to quit the game.");
}

// Function to take the real time input and
// set the 'flag' variable accordingly
void input() {
    if (kbhit()) {
        switch (tolower(getch())) {
        case 'a':
            if(key!=2)
            key = 1;
            break;
        case 'd':
            if(key!=1)
            key = 2;
            break;
        case 'w':
            if(key!=4)
            key = 3;
            break;
        case 's':
            if(key!=3)
            key = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

// Function for the movement logic that
// checks eat, move, collisions
void logic() {
    
    // Updating the coordinates for continous
    // movement of snake
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
    // Changing the direction of movement of snake
    switch (key) {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }

    // If the game is over
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameover = 1;
        
    // Checks for collision with the tail (o)
    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            gameover = 1;
    }

    // If snake reaches the fruit
    // then update the score
    if (x == fruitx && y == fruity) {
        fruitx = rand() % WIDTH;
        fruity = rand() % HEIGHT;
        while (fruitx == 0)
            fruitx = rand() % WIDTH;

        // Generation of new fruit
        while (fruity == 0)
            fruity = rand() % HEIGHT;
        score += 10;
         snakeTailLen++;
    }
}

void main() {
  
    // Initial set up that initialize the
    // required variables
    setup();

    // Game loop starts here
    while (!gameover) {

        // Functions that will be called
        // repeatedly after the given interval
        draw();
        input();
        logic();
        Sleep(33);
    }
}
