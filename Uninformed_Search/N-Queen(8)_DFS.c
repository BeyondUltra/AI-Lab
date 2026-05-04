#include <stdio.h>

#define N 8

int board[N];

int isSafe(int r,int c){
    for(int i=0;i<r;i++)
        if(board[i]==c || abs(board[i]-c)==abs(i-r))
            return 0;
    return 1;
}

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf(board[i]==j?"Q ":". ");
        printf("\n");
    }
    printf("\n");
}

void DFS(int r){
    if(r==N){
        print();
        return;
    }

    for(int c=0;c<N;c++){
        if(isSafe(r,c)){
            board[r]=c;
            DFS(r+1);
        }
    }
}

int main(){
    DFS(0);
    return 0;
}
