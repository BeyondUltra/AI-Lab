#include <stdio.h>

#define N 5

int graph[N][N]={
    {0,2,0,1,0},
    {2,0,3,2,0},
    {0,3,0,0,1},
    {1,2,0,0,3},
    {0,0,1,3,0}
};

int h[N]={7,6,2,1,0};

int visited[N];

void Astar(int start,int goal){

    int g[N]={0};
    int f[N];

    for(int i=0;i<N;i++)
        f[i]=999;

    f[start]=h[start];

    while(1){
        int min=999, cur=-1;

        for(int i=0;i<N;i++)
            if(!visited[i] && f[i]<min){
                min=f[i];
                cur=i;
            }

        if(cur==-1) break;

        printf("Visited node: %d\n",cur);

        if(cur==goal){
            printf("Goal reached!\n");
            return;
        }

        visited[cur]=1;

        for(int i=0;i<N;i++){
            if(graph[cur][i]){
                int cost = g[cur] + graph[cur][i];
                if(cost < g[i] || g[i]==0){
                    g[i]=cost;
                    f[i]=g[i]+h[i];
                }
            }
        }
    }
}

int main(){
    Astar(0,4);
    return 0;
}
