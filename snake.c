#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int snakeX[100], snakeY[100];

int x = WIDTH / 2 , y = HEIGHT / 2;

int fruitX , fruitY;

int snakeLength = 5;

bool gameover = false;

void createFood(){
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    for (int i = 0;i < snakeLength;i++){
        if (fruitX == snakeX[i] && fruitY == snakeY[i]){
            createFood();
            break;
        }
    }
}

void userInput(){
    if (kbhit()){
        char move = tolower(getch());
        if (move == 'w'){
            y--;
        }else if(move == 'a'){
            x--;
        }else if(move == 's'){
            y++;
        }else if(move == 'd'){
            x++;
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
                for (int k = 0;k < snakeLength ;k++){
                    if (j == snakeX[k] && i == snakeY[k]){
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

void movement(){
    int prevX = snakeX[0];
    int prevY = snakeY[0];
    int prev2X, prev2Y;
    snakeX[0] = x;
    snakeY[0] = y;
    for (int i = 1; i < snakeLength; i++) {
        prev2X = snakeX[i];
        prev2Y = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}

int main(){
    snakeX[0] = x;
    snakeY[0] = y;
    createFood();


    while (!gameover){
        userInput();
        movement();
        draw();
        Sleep(33);
    }

    return 0;
}