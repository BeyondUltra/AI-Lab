#include <stdio.h>

#define R 3
#define C 3

int maze[R][C] = {
    {0,0,0},
    {1,0,1},
    {0,0,0}
};

int visited[R][C] = {0};

// -------- DLS --------
void DLS(int x, int y, int d){

    // boundary + wall + visited check
    if(x<0 || y<0 || x>=R || y>=C || maze[x][y]==1 || visited[x][y])
        return;

    printf("(%d,%d) depth=%d\n", x, y, d);

    // mark visited
    visited[x][y] = 1;

    // depth limit
    if(d == 0){
        visited[x][y] = 0; // backtrack
        return;
    }

    // explore all directions
    DLS(x-1, y, d-1); // up
    DLS(x+1, y, d-1); // down
    DLS(x, y-1, d-1); // left
    DLS(x, y+1, d-1); // right

    // backtrack
    visited[x][y] = 0;
}

// -------- MAIN --------
int main(){
    DLS(0,0,3); // start from (0,0), depth limit 3
    return 0;
}
