#include <stdio.h>

#define MAX 100

typedef struct{
    int m, c, boat;
}State;

int visited[4][4][2];

// Validate state
int isValid(int m, int c){
    if(m<0 || c<0 || m>3 || c>3) return 0;
    if(m>0 && m<c) return 0;
    if((3-m)>0 && (3-m)<(3-c)) return 0;
    return 1;
}

// 🔥 Better printing
void printState(State s){
    printf("\nLeft Side  -> M=%d C=%d\n", s.m, s.c);
    printf("Right Side -> M=%d C=%d\n", 3-s.m, 3-s.c);

    if(s.boat==1)
        printf("Boat is on LEFT side\n");
    else
        printf("Boat is on RIGHT side\n");

    printf("-------------------------\n");
}

void BFS(){
    State queue[MAX];
    int front=0, rear=0;

    queue[rear++] = (State){3,3,1};
    visited[3][3][1]=1;

    printf("MISSIONARY CANNIBAL (BFS)\n");

    while(front<rear){
        State cur = queue[front++];

        printState(cur);

        if(cur.m==0 && cur.c==0){
            printf("🎯 Goal reached!\n");
            return;
        }

        int moves[5][2] = {
            {1,0}, // 1M
            {2,0}, // 2M
            {0,1}, // 1C
            {0,2}, // 2C
            {1,1}  // 1M 1C
        };

        for(int i=0;i<5;i++){
            State next;

            if(cur.boat==1){ // left → right
                next.m = cur.m - moves[i][0];
                next.c = cur.c - moves[i][1];
                next.boat = 0;
            }else{ // right → left
                next.m = cur.m + moves[i][0];
                next.c = cur.c + moves[i][1];
                next.boat = 1;
            }

            if(isValid(next.m,next.c) && !visited[next.m][next.c][next.boat]){
                visited[next.m][next.c][next.boat]=1;
                queue[rear++] = next;
            }
        }
    }
}

int main(){
    BFS();
    return 0;
}
