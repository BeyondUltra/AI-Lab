#include <stdio.h>

#define R 5
#define C 5

int maze[R][C]={
 {0,0,1,0,0},
 {1,0,1,0,1},
 {0,0,0,0,0},
 {0,1,1,1,0},
 {0,0,0,1,0}
};

int visited[R][C];

void DFS(int x,int y){

    if(x<0||y<0||x>=R||y>=C||maze[x][y]==1||visited[x][y])
        return;

    printf("Visited (%d,%d)\n",x,y);

    visited[x][y]=1;

    DFS(x-1,y);
    DFS(x+1,y);
    DFS(x,y-1);
    DFS(x,y+1);
}

int main(){
    DFS(0,0);
    return 0;
}
