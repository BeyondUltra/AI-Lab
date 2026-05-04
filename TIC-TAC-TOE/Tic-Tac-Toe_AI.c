#include <stdio.h>
#define HUMAN 'O'
#define AI 'X'
#define EMPTY ' '

char board[9]={
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
};

void printBoard(){
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

int checkWin(char player){
    int winCombos[8][3]={
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for(int i=0;i<8;i++){
        if(board[winCombos[i][0]]==player && board[winCombos[i][1]]==player && board[winCombos[i][2]]==player)
            return 1;
    }
    return 0;
}

int isDraw(){
    for(int i=0;i<9;i++)
        if(board[i]==EMPTY)
            return 0;
    return 1;
}

int minimax(int isMaximizing){
    if(checkWin(AI))
        return 10;
    if(checkWin(HUMAN))
        return -10;
    if(isDraw())
        return 0;
    if(isMaximizing){
        int best=-1000;
        for(int i=0;i<9;i++){
            if(board[i]==EMPTY){
                board[i]=AI;
                int score=minimax(0);
                board[i]=EMPTY;
                if(score>best)
                    best=score;
            }
        }
        return best;
    }else{
        int best=1000;
        for(int i=0;i<9;i++){
            if(board[i]==EMPTY){
                board[i]=HUMAN;
                int score=minimax(1);
                board[i]=EMPTY;
                if(score<best)
                    best=score;
            }
        }
        return best;
    }
}

int bestMove(){
    int bestScore=-1000;
    int move=-1;
    for(int i=0;i<9;i++){
        if(board[i]==EMPTY){
            board[i]=AI;
            int score=minimax(0);
            board[i]=EMPTY;
            if(score>bestScore){
                bestScore=score;
                move=i;
            }
        }
    }
    return move;
}

int main(){
    int humanMove;
    printf("TIC TAC TOE USING AI (MINIMAX)\n");
    printf("\nBoard Positions:\n");
    printf(" 0 | 1 | 2 \n");
    printf("-----------\n");
    printf(" 3 | 4 | 5 \n");
    printf("-----------\n");
    printf(" 6 | 7 | 8 \n");
    while(1){
        printBoard();
        printf("\nEnter your move (0-8): ");
        scanf("%d", &humanMove);
        if(humanMove<0 || humanMove>8 || board[humanMove]!=EMPTY){
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[humanMove]=HUMAN;
        if(checkWin(HUMAN)){
            printBoard();
            printf("\nYou Win!\n");
            break;
        }
        if(isDraw()){
            printBoard();
            printf("\nGame Draw!\n");
            break;
        }
        int aiMove=bestMove();
        board[aiMove]=AI;
        if(checkWin(AI)){
            printBoard();
            printf("\nAI Wins!\n");
            break;
        }
        if(isDraw()){
            printBoard();
            printf("\nGame Draw!\n");
            break;
        }
    }
    return 0;
}
