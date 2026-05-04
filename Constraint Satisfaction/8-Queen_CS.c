#include <stdio.h>
#include <stdlib.h>

#define N 8

int board[N];

int isSafe(int r, int c){
    for(int i=0;i<r;i++){
        if(board[i]==c || abs(board[i]-c)==abs(i-r))
            return 0;
    }
    return 1;
}

void solve(int r){
    if(r==N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                printf(board[i]==j?"Q ":". ");
            printf("\n");
        }
        printf("\n");
        return;
    }

    for(int c=0;c<N;c++){
        if(isSafe(r,c)){
            board[r]=c;
            solve(r+1);
        }
    }
}

int main(){
    solve(0);
    return 0;
}
