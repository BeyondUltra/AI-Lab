#include <stdio.h>

#define MAX 100

struct State{
    int x, y;
};

int visited[5][5]; // assuming max capacity 4

void BFS(int jug1, int jug2, int target){
    struct State queue[MAX];
    int front = 0, rear = 0;

    queue[rear].x = 0;
    queue[rear].y = 0;
    rear++;

    visited[0][0] = 1;

    while(front < rear){
        struct State cur = queue[front++];

        printf("(%d, %d)\n", cur.x, cur.y);

        if(cur.x == target || cur.y == target){
            printf("Target reached!\n");
            return;
        }

        struct State next[6];

        // fill jug1
        next[0].x = jug1;
        next[0].y = cur.y;

        // fill jug2
        next[1].x = cur.x;
        next[1].y = jug2;

        // empty jug1
        next[2].x = 0;
        next[2].y = cur.y;

        // empty jug2
        next[3].x = cur.x;
        next[3].y = 0;

        // pour jug1 -> jug2
        int pour1 = (jug2 - cur.y < cur.x) ? (jug2 - cur.y) : cur.x;
        next[4].x = cur.x - pour1;
        next[4].y = cur.y + pour1;

        // pour jug2 -> jug1
        int pour2 = (jug1 - cur.x < cur.y) ? (jug1 - cur.x) : cur.y;
        next[5].x = cur.x + pour2;
        next[5].y = cur.y - pour2;

        for(int i = 0; i < 6; i++){
            int nx = next[i].x;
            int ny = next[i].y;

            if(nx >= 0 && ny >= 0 && nx <= jug1 && ny <= jug2 && !visited[nx][ny]){
                visited[nx][ny] = 1;
                queue[rear++] = next[i];
            }
        }
    }
}

int main(){
    BFS(4, 3, 2);
    return 0;
}
