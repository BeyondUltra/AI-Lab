#include <stdio.h>

#define N 5

int graph[N][N]={
    {0,2,0,1,0},
    {2,0,3,2,0},
    {0,3,0,0,1},
    {1,2,0,0,3},
    {0,0,1,3,0}
};

int h[N]={7,6,2,1,0}; // heuristic to goal

int visited[N];

void BestFirst(int start, int goal){

    int open[N], size=0;

    open[size++]=start;

    while(size>0){

        int best=0;
        for(int i=1;i<size;i++)
            if(h[open[i]] < h[open[best]])
                best=i;

        int cur=open[best];
        open[best]=open[--size];

        printf("Visited node: %d\n",cur);

        if(cur==goal){
            printf("Goal reached!\n");
            return;
        }

        visited[cur]=1;

        for(int i=0;i<N;i++){
            if(graph[cur][i] && !visited[i])
                open[size++]=i;
        }
    }
}

int main(){
    BestFirst(0,4);
    return 0;
}
