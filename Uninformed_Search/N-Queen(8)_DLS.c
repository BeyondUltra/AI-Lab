#include <stdio.h>
#include <stdlib.h>
#define N 8

int board[N];

// -------- CHECK SAFE --------
int isSafe(int r, int c){
    for(int i=0;i<r;i++){
        if(board[i] == c || abs(board[i] - c) == abs(i - r))
            return 0;
    }
    return 1;
}

// -------- PRINT BOARD --------
void print(){
    printf("\nSolution:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// -------- DLS (BACKTRACKING) --------
void DLS(int r, int d){

    // solution found
    if(r == N){
        print();
        return;
    }

    // depth limit
    if(d == 0) return;

    for(int c=0;c<N;c++){
        if(isSafe(r,c)){
            board[r] = c;
            DLS(r+1, d-1);
        }
    }
}

// -------- MAIN --------
int main(){
    DLS(0, N);  // start from row 0, depth = N
    return 0;
}

