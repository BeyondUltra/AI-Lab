#include <stdio.h>

int visited[5][5]; // assuming max capacity 4

void DLS(int x, int y, int jug1, int jug2, int target, int d){

    printf("(%d, %d) depth=%d\n", x, y, d);

    if(x == target || y == target){
        printf("Target reached!\n");
        return;
    }

    if(d == 0) return;

    visited[x][y] = 1;

    int nx, ny;

    // fill jug1
    nx = jug1; ny = y;
    if(!visited[nx][ny])
        DLS(nx, ny, jug1, jug2, target, d-1);

    // fill jug2
    nx = x; ny = jug2;
    if(!visited[nx][ny])
        DLS(nx, ny, jug1, jug2, target, d-1);

    // empty jug1
    nx = 0; ny = y;
    if(!visited[nx][ny])
        DLS(nx, ny, jug1, jug2, target, d-1);

    // empty jug2
    nx = x; ny = 0;
    if(!visited[nx][ny])
        DLS(nx, ny, jug1, jug2, target, d-1);

    // pour jug1 -> jug2
    int pour1 = (jug2 - y < x) ? (jug2 - y) : x;
    nx = x - pour1;
    ny = y + pour1;
    if(!visited[nx][ny])
        DLS(nx, ny, jug1, jug2, target, d-1);

    // pour jug2 -> jug1
    int pour2 = (jug1 - x < y) ? (jug1 - x) : y;
    nx = x + pour2;
    ny = y - pour2;
    if(!visited[nx][ny])
        DLS(nx, ny, jug1, jug2, target, d-1);
}

int main(){

    int jug1 = 4, jug2 = 3, target = 2;
    int depth = 3;

    printf("WATER JUG USING DLS (depth = %d)\n\n", depth);

    DLS(0, 0, jug1, jug2, target, depth);

    return 0;
}
