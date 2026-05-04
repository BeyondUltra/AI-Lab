#include <stdio.h>
#define EMPTY ' '

int magicSquare[9]={
    8, 3, 4,
    1, 5, 9,
    6, 7, 2
};
char board[9];
int playerMoves[5], computerMoves[5];
int pCount=0, cCount=0;

void initBoard(){
    for(int i=0;i<9;i++)
        board[i]=EMPTY;
}

void displayBoard(){
    printf("\n");
    for(int i=0;i<9;i++){
        printf(" %c ", board[i]);
        if(i%3!=2)
            printf("|");
        if(i%3==2 && i!=8)
            printf("\n------------\n");
    }
    printf("\n");
}

int checkWin(int moves[], int count){
    if(count<3)
        return 0;
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            for(int k=j+1;k<count;k++){
                if(moves[i]+moves[j]+moves[k]==15)
                    return 1;
            }
        }
    }
    return 0;
}

int findWinningMove(int moves[], int count){
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            int needed=15-(moves[i]+moves[j]);
            for(int k=0;k<9;k++){
                if(magicSquare[k]==needed && board[k]==EMPTY)
                    return k;
            }
        }
    }
    return -1;
}

int boardFull(){
    for(int i=0;i<9;i++)
        if(board[i]==EMPTY)
            return 0;
    return 1;
}

int main(){
    int move;
    initBoard();
    printf("Tic-Tac-Toe using Magic Square\n");
    while (1){
        displayBoard();
        printf("\nEnter your move (1-9): ");
        scanf("%d", &move);
        move--;
        if(move<0 || move>8 || board[move]!=EMPTY){
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[move]='X';
        playerMoves[pCount++]=magicSquare[move];
        if(checkWin(playerMoves, pCount)){
            displayBoard();
            printf("\nYou win!\n");
            break;
        }
        if(boardFull()){
            displayBoard();
            printf("\nGame Draw!\n");
            break;
        }
        int winMove=findWinningMove(computerMoves, cCount);

        int blockMove=findWinningMove(playerMoves, pCount);
        if(winMove!=-1)
            move=winMove;
        else if(blockMove!=-1)
            move=blockMove;
        else{
            for(int i=0;i<9;i++){
                if(board[i]==EMPTY){
                    move=i;
                    break;
                }
            }
        }
        board[move]='O';
        computerMoves[cCount++]=magicSquare[move];
        if(checkWin(computerMoves, cCount)){
            displayBoard();
            printf("\nComputer wins!\n");
            break;
        }
    }
    return 0;
}
