#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int snakeX[100], sankeY[100];

int x = WIDTH / 2 , y = HEIGHT / 2;

int fruitX , fruitY;

int snakeLength = 5;

void createFood(){
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    for (int i = 0;i < snakeLength;i++){
        if (fruitX == snakeX[i] && fruitY == sankeY[i]){
            createFood();
            break;
        }
    }
}


void userInput(){
    if (kbhit()){
        char move = tolower(getch());
        if (move == 'w'){
            printf("You pressed W\n");
        }else if(move == 'a'){
            printf("You pressed A\n");
        }else if(move == 's'){
            printf("You pressed S\n");
        }else if(move == 'd'){
            printf("You pressed D\n");
        }
    }
}

void draw(){
    system("cls");
    for (int i = 0;i < HEIGHT;i++){
        for (int j = 0;j < WIDTH;j++){
            if (i == 0 || i == HEIGHT - 1){
                printf("#");
            }else if (j == 0 || j == WIDTH - 1){
                printf("#");
            }else{
                bool isSnake = false;
                for (int i = 0;i < snakeLength ;i++){
                    if (j == snakeX[i] && i == sankeY[i]){
                        printf("O");
                        isSnake = true;
                    }
                }
                if (!isSnake){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}


int main(){
    createFood();

    while (true){
        userInput();
        draw();
        Sleep(33);
    }

    return 0;
}