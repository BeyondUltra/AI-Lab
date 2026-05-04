#include <stdio.h>

#define N 4

int graph[N][N]={
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
};

int color[N];

int isSafe(int v,int c){
    for(int i=0;i<N;i++)
        if(graph[v][i] && color[i]==c)
            return 0;
    return 1;
}

void solve(int v){
    if(v==N){
        for(int i=0;i<N;i++)
            printf("Vertex %d -> Color %d\n",i,color[i]);
        printf("\n");
        return;
    }

    for(int c=1;c<=3;c++){
        if(isSafe(v,c)){
            color[v]=c;
            solve(v+1);
        }
    }
}

int main(){
    solve(0);
    return 0;
}
