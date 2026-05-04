#include <stdio.h>
#include <stdlib.h>

#define N 4
#define MAX 100

typedef struct{
    int board[N];
    int row;
}State;

int isSafe(int board[], int row, int col){
    for(int i=0;i<row;i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}

void printBoard(int board[]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i]==j) printf("Q ");
            else printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void BFS(){
    State queue[MAX];
    int front=0, rear=0;

    State start;
    start.row=0;

    queue[rear++] = start;

    while(front<rear){
        State cur = queue[front++];

        if(cur.row==N){
            printBoard(cur.board);
            continue;
        }

        for(int col=0;col<N;col++){
            if(isSafe(cur.board,cur.row,col)){
                State next = cur;
                next.board[cur.row]=col;
                next.row++;

                queue[rear++] = next;
            }
        }
    }
}

int main(){
    BFS();
    return 0;
}
