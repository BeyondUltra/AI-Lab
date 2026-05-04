#include <stdio.h>

int visited[5][5];

void DFS(int x, int y, int jug1, int jug2, int target){

    printf("(%d, %d)\n", x, y);

    if(x==target || y==target){
        printf("Target reached!\n");
        return;
    }

    visited[x][y]=1;

    int nx, ny;

    // fill jug1
    nx=jug1; ny=y;
    if(!visited[nx][ny]) DFS(nx,ny,jug1,jug2,target);

    // fill jug2
    nx=x; ny=jug2;
    if(!visited[nx][ny]) DFS(nx,ny,jug1,jug2,target);

    // empty jug1
    nx=0; ny=y;
    if(!visited[nx][ny]) DFS(nx,ny,jug1,jug2,target);

    // empty jug2
    nx=x; ny=0;
    if(!visited[nx][ny]) DFS(nx,ny,jug1,jug2,target);

    // pour jug1 → jug2
    int pour = (jug2-y < x) ? jug2-y : x;
    nx = x - pour;
    ny = y + pour;
    if(!visited[nx][ny]) DFS(nx,ny,jug1,jug2,target);

    // pour jug2 → jug1
    pour = (jug1-x < y) ? jug1-x : y;
    nx = x + pour;
    ny = y - pour;
    if(!visited[nx][ny]) DFS(nx,ny,jug1,jug2,target);
}

int main(){
    DFS(0,0,4,3,2);
    return 0;
}
