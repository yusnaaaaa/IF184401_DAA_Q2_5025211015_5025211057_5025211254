#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define INTMIN INT_MIN
#define INTMAX INT_MAX

char arr[3][3]= {'.','.','.',
                '.','.','.',
                '.','.','.'};

void gameBoard(){
    printf("%c  %c  %c \n%c  %c  %c \n%c  %c  %c \n", arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2], arr[2][0], arr[2][1], arr[2][2]);
}

char result(){
    if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0]!='.'){
            return arr[0][0];
    }
    if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1]!='.'){
            return arr[0][1];
    }
    if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2]!='.'){
            return arr[0][2];
    }
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2]!='.'){
            return arr[0][0];
    }
    if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2]!='.'){
            return arr[1][0];
    }
    if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2]!='.'){
            return arr[2][0];
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2]!='.'){
        return arr[0][0];
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0]!='.'){
        return arr[0][2];
    }

    bool cek = true;
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
          if(arr[i][j] == '.') {
            cek = false;
            break;
          }
       }
    }

    if(cek) return 'T';
    return '-';
}

int minimax(int depth, bool isMaximizing){

    int score, bestScore;
    char res = result();

    if(isMaximizing){
        bestScore = INTMIN;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(arr[i][j]=='.'){
                    arr[i][j]='O';
                    score = minimax(depth+1, false);
                    arr[i][j]='.';
                    if(score > bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        return bestScore;
    }
}

void bestMove(){
    int score;
    int bestScore = 0, x, y;
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
          if(arr[i][j]=='.'){
            score = minimax(0, false);
            arr[i][j]='.';
            if(score > bestScore){
                bestScore = score;
                x = i;
                y = j;
            }
          }
       }
    }
    arr[x][y]='O';
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

                if(arr[x][y]=='X' || arr[x][y]=='O' || x<0 || x>2 || y<0 || y>2) continue;
                if(player==2) arr[x][y] = 'O';
                else arr[x][y] = 'X';

                gameBoard();

                res = result();
                if(res!='-' && level == 2) {
                    if(res == 'O') printf("Player2 wins.\n");
                    else if (res == 'X') printf("Player1 wins.\n");
                    else if (res == 'T') printf("Draw.\n");
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
                    if(arr[x][y]=='X' || arr[x][y]=='O' || x<0 || x>2 || y<0 || y>2) continue;
                    arr[x][y] = 'X';
                    cnt++;
                }
                else {
                    printf("\nBot\n");
                    srand(time(0)); // adding random by time
                    while(1){
                        x = rand()%3;
                        y = rand()%3;
                        if(arr[x][y]=='.') break;
                    }
                    arr[x][y] = 'O';
                    cnt++;
                }

                gameBoard();
                
                res = result();
                if(res!='-') {
                    if(res == 'O') printf("Bot wins.\n");
                    else if (res == 'X') printf("Player wins.\n");
                    else if (res == 'T') printf("Draw.\n");
                    break;
                }

            }
        }
        if(level==3){
            gameBoard();
            int turn;
            printf("Bot go first? (1/0) : ");
            scanf("%d", &turn);

            if(turn) cnt++;
            while(1){
                if(cnt%2==0){
                    printf("\nPlayer your move: ");
                    scanf("%d %d", &x, &y);
                    if(arr[x][y]=='X' || arr[x][y]=='O' || x<0 || x>2 || y<0 || y>2) continue;
                    arr[x][y] = 'X';
                    cnt++;
                }
                else {
                    printf("\nAI\n");
                    bestMove();
                    cnt++;
                }

                gameBoard();
                res = result();
                if(res!='-') {
                    if(res == 'O') printf("AI wins.\n");
                    else if (res == 'X') printf("Player wins.\n");
                    else if (res == 'T') printf("Draw.\n");
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