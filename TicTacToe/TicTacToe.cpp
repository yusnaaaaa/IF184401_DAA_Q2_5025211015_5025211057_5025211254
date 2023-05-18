#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

char arr[3][3]= {'.','.','.',
                '.','.','.',
                '.','.','.'};

void gameBoard(){
    printf("%c  %c  %c \n%c  %c  %c \n%c  %c  %c \n", arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2], arr[2][0], arr[2][1], arr[2][2]);
}

int main (){
    printf("Level 1 : Two Player Game\n");
    printf("Level 2 : Player vs Bot\n");
    printf("Level 3 : Player vs AI\n\n");

    while(1){
        int level;
        char res='-';

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                arr[i][j]='.';
            }
        }

        printf("\nSelect Level : ");
        scanf("%d", &level);

        int player=1, x, y, cnt=0;
        if(level==1){
            gameBoard();
            while(1){
                printf("\nPlayer%d your move: ", player);
                scanf("%d %d", &x, &y);

                if(player==2) arr[x][y] = 'O';
                else arr[x][y] = 'X';

                gameBoard();

                if(cnt==9 && level ==1){
                    printf("Game finished\n");
                    break;
                }

                player++;
                player = (player % 2) ? 1 : 2;
            }
        }

        if(level==2){
            gameBoard();
            while(1){
                if(cnt%2==0){
                    printf("\nPlayer your move: ");
                    scanf("%d %d", &x, &y);
                    arr[x][y] = 'X';
                    cnt++;
                }
                else {

                    printf("\nBot\n");
                    while(1){
                        x = rand()%3;
                        y = rand()%3;
                        if(arr[x][y]=='.') break;
                    }
                    arr[x][y] = 'O';
                    cnt++;
                }

                gameBoard();
                
                if(cnt==9 && level ==1){
                    printf("Game finished\n");
                    break;
                }

            }
        }
        int repeat;
        printf("\nPlay again? (1/0) : ");
        scanf("%d", &repeat);
        if (repeat == 0) return 0;
    }
}
