#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct{
    int mat[3][3];
    int x, y;
    int h;
}State;

State open[MAX];
int size = 0;

int goal[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

int visited[MAX][9], vcount=0;

// -------- COPY --------
void copy(int a[3][3], int b[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            b[i][j]=a[i][j];
}

// -------- PRINT --------
void print(int a[3][3]){
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

// -------- HEURISTIC --------
int heuristic(int a[3][3]){
    int h=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[i][j]!=0 && a[i][j]!=goal[i][j])
                h++;
    return h;
}

// -------- VISITED CHECK --------
int isVisited(int a[3][3]){
    for(int i=0;i<vcount;i++){
        int same=1;
        for(int j=0;j<9;j++){
            if(visited[i][j] != a[j/3][j%3]){
                same=0;
                break;
            }
        }
        if(same) return 1;
    }
    return 0;
}

// -------- MARK VISITED --------
void markVisited(int a[3][3]){
    for(int i=0;i<9;i++)
        visited[vcount][i] = a[i/3][i%3];
    vcount++;
}

// -------- INSERT (sorted by h ascending) --------
void insert(State s){
    int i=size-1;
    while(i>=0 && open[i].h > s.h){
        open[i+1]=open[i];
        i--;
    }
    open[i+1]=s;
    size++;
}

// -------- FIXED POP --------
State pop(){
    State s = open[0];
    for(int i=0;i<size-1;i++)
        open[i] = open[i+1];
    size--;
    return s;
}

// -------- BEST FIRST --------
void BestFirst(int start[3][3], int x, int y){

    State first;
    copy(start, first.mat);
    first.x=x; first.y=y;
    first.h = heuristic(start);

    insert(first);

    while(size>0){

        State cur = pop();

        if(isVisited(cur.mat)) continue;

        print(cur.mat);

        if(cur.h==0){
            printf("Goal reached!\n");
            return;
        }

        markVisited(cur.mat);

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx>=0 && nx<3 && ny>=0 && ny<3){

                State next;
                copy(cur.mat, next.mat);

                next.mat[cur.x][cur.y] = next.mat[nx][ny];
                next.mat[nx][ny] = 0;

                next.x=nx;
                next.y=ny;
                next.h = heuristic(next.mat);

                if(!isVisited(next.mat))
                    insert(next);
            }
        }
    }

    printf("No solution found\n");
}

// -------- MAIN --------
int main(){
    int start[3][3]={{1,2,3},{4,0,6},{7,5,8}};
    BestFirst(start,1,1);
    return 0;
}
