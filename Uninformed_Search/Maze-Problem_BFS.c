#include <stdio.h>

#define ROW 5
#define COL 5
#define MAX 100

typedef struct{
    int x, y;
}Point;

int maze[ROW][COL] = {
    {0,0,1,0,0},
    {1,0,1,0,1},
    {0,0,0,0,0},
    {0,1,1,1,0},
    {0,0,0,1,0}
};

int visited[ROW][COL];

void BFS(int sx, int sy, int dx, int dy){

    Point queue[MAX];
    int front=0, rear=0;

    queue[rear++] = (Point){sx, sy};
    visited[sx][sy] = 1;

    while(front < rear){

        Point cur = queue[front++];

        printf("Visited: (%d, %d)\n", cur.x, cur.y);

        if(cur.x == dx && cur.y == dy){
            printf("Destination reached!\n");
            return;
        }

        int dxs[4] = {-1,1,0,0};
        int dys[4] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nx = cur.x + dxs[i];
            int ny = cur.y + dys[i];

            if(nx>=0 && nx<ROW && ny>=0 && ny<COL &&
               maze[nx][ny]==0 && !visited[nx][ny]){

                visited[nx][ny] = 1;
                queue[rear++] = (Point){nx, ny};
            }
        }
    }

    printf("No path found!\n");
}

int main(){

    int startX = 0, startY = 0;
    int destX = 4, destY = 4;

    printf("BFS MAZE TRAVERSAL\n");
    printf("0 = Path, 1 = Wall\n\n");

    BFS(startX, startY, destX, destY);

    return 0;
}
