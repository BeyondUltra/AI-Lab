#include <stdio.h>

#define MAX 1000

typedef struct{
    int mat[3][3];
    int x,y;
    int g,h,f;
}State;

State open[MAX];
int size=0;

int goal[3][3]={{1,2,3},{4,5,6},{7,8,0}};

int heuristic(int a[3][3]){
    int h=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[i][j]!=0 && a[i][j]!=goal[i][j])
                h++;
    return h;
}

void copy(int a[3][3], int b[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            b[i][j]=a[i][j];
}

void insert(State s){
    int i=size-1;
    while(i>=0 && open[i].f > s.f){
        open[i+1]=open[i];
        i--;
    }
    open[i+1]=s;
    size++;
}

State pop(){
    return open[--size];
}

void Astar(int start[3][3], int x,int y){

    State first;
    copy(start, first.mat);
    first.x=x; first.y=y;
    first.g=0;
    first.h=heuristic(start);
    first.f=first.g + first.h;

    insert(first);

    while(size>0){
        State cur=pop();

        printf("\nState (f=%d):\n",cur.f);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                printf("%d ",cur.mat[i][j]);
            printf("\n");
        }

        if(cur.h==0){
            printf("Goal reached!\n");
            return;
        }

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx>=0 && nx<3 && ny>=0 && ny<3){

                State next;
                copy(cur.mat,next.mat);

                next.mat[cur.x][cur.y]=next.mat[nx][ny];
                next.mat[nx][ny]=0;

                next.x=nx; next.y=ny;

                next.g=cur.g+1;
                next.h=heuristic(next.mat);
                next.f=next.g + next.h;

                insert(next);
            }
        }
    }
}

int main(){
    int start[3][3]={{1,2,3},{4,0,6},{7,5,8}};
    Astar(start,1,1);
    return 0;
}
