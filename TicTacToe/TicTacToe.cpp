#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char arr[3][3]= {'.','.','.',
                '.','.','.',
                '.','.','.'};

void mainScreen(){
    printf("================= Tic Tac Toe =================\n\n");
    printf("\tLevel 1 : Two Player Game\n");
    printf("\tLevel 2 : Player vs Bot\n");
    printf("\tLevel 3 : Player vs AI\n\n");
    printf("===============================================\n");
}

void gameBoard(char* P1, char* P2) {
    printf("=============== Tic Tac Toe ===============\n\n");
    printf("\t\t %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("\t\t---+---+---\n");
    printf("\t\t %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("\t\t---+---+---\n");
    printf("\t\t %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);
    printf("\n\t %s : 'X'\t %s : 'O'\n", P1,P2);
    printf("===========================================\n");
}

void init(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j]='.';
        }
    }
}

char result(){
    for (int i = 0; i < 3; i++){
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2]!='.'){
            return arr[i][0];
        }
    }

    for (int i = 0; i < 3; i++){
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i]!='.'){
            return arr[0][i];
        }
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

    int score;
    char res = result();
    if (res=='O') {
        score = 1;
        return score;
    }
    else if (res=='X') {
        score = -1;
        return score;
    }
    else if (res=='T') {
        score = 0;
        return score;
    }

    if(isMaximizing){
        int bestScore = -1000;
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
        int bestScore = 1000;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(arr[i][j]=='.'){
                    arr[i][j]='X';
                    score = minimax(depth+1, true);
                    arr[i][j]='.';
                    if(score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

void bestMove(){
    int score;
    int bestScore = -1000, x, y;
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
          if(arr[i][j]=='.'){
            arr[i][j]='O';
            score = minimax(0, false);
            arr[i][j]='.';
            if(score > bestScore){
                bestScore = score;
                x=i; y=j;
            }
          }
       }
    }
    arr[x][y]='O';
}

int main (){
    while(1){
        system("cls");
        mainScreen();
        int level;
        char res='-';
        printf("\n\t      Select Level : ");
        init();
        scanf("%d", &level);

        int player=1, x, y, cnt=0;
        if(level==1){

            while(1){
                system("cls");
                gameBoard("Player 1", "Player 2");
                printf("\n\t    Player %d your move: \n\t\t    ", player);
                scanf("%d %d", &x, &y);

                if(arr[x][y]=='X' || arr[x][y]=='O' || x<0 || x>2 || y<0 || y>2) continue;

                if(player==2) arr[x][y] = 'O';
                else arr[x][y] = 'X';

                cnt++;
                res = result();
                if(res!='-') {
                    system("cls");
                    gameBoard("Player 1", "Player 2");
                    if(res == 'O')          printf("\n\t\tPlayer 2 Win.\n");
                    else if (res == 'X')    printf("\n\t\tPlayer 1 Win.\n");
                    else if (res == 'T')    printf("\n\t\t   Draw.\n");
                    break;
                }

                player++;
                player = (player % 2) ? 1 : 2;
            }
        }

        if(level==2){
            int turn;
            system("cls");
            printf("Bot go first? (1/0) : ");
            scanf("%d", &turn);

            if(turn) cnt++;
            while(1){
                system("cls");
                gameBoard("Player", "Bot");
                if(cnt%2==0){
                    printf("\n\t     Player your move: \n\t\t    ");
                    scanf("%d %d", &x, &y);
                    if(arr[x][y]=='X' || arr[x][y]=='O' || x<0 || x>2 || y<0 || y>2) continue;
                    arr[x][y] = 'X';
                    cnt++;
                }
                else {

                    printf("\nBot\n");
                    srand(time(0));
                    while(1){
                        x = rand()%3;
                        y = rand()%3;
                        if(arr[x][y]=='.') break;
                    }
                    arr[x][y] = 'O';
                    cnt++;
                }
                res = result();
                if(res!='-') {
                    system("cls");
                    gameBoard("Player", "Bot");
                    if(res == 'O')          printf("\n\t\t  Bot Win.\n");
                    else if (res == 'X')    printf("\n\t\tPlayer Win.\n");
                    else if (res == 'T')    printf("\n\t\t   Draw.\n");
                    break;
                }

            }
        }

        if(level==3){
            int turn;
            system("cls");
            printf("AI go first? (1/0) : ");
            scanf("%d", &turn);

            if(turn) cnt++;
            while(1){
                system("cls");
                gameBoard("Player", "AI");
                if(cnt%2==0){
                    printf("\n\t     Player your move: \n\t\t    ");
                    scanf("%d %d", &x, &y);
                    if(arr[x][y]=='X' || arr[x][y]=='O' || x<0 || x>2 || y<0 || y>2) continue;
                    arr[x][y] = 'X';
                    cnt++;
                }
                else {
                    printf("\nBot\n");
                    bestMove();
                    cnt++;
                }

                res = result();
                if(res!='-') {
                    system("cls");
                    gameBoard("Player", "AI");
                    if(res == 'O')          printf("\n\t\t  AI Win.\n");
                    else if (res == 'X')    printf("\n\t\tPlayer Win.\n");
                    else if (res == 'T')    printf("\n\t\t  Draw.\n");
                    break;
                }
            }
        }
        int repeat;
        printf("\n===========================================\n\n");
        printf("\t   Play again? (1/0) : ");
        scanf("%d", &repeat);
        if (repeat == 0) return 0;
    }
}
