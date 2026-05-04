#include <stdio.h>

int visited[10000][9], vcount=0;

void print(int a[9]){
    for(int i=0;i<9;i++){
        printf("%d ",a[i]);
        if(i%3==2) printf("\n");
    }
    printf("\n");
}

int isGoal(int a[]){
    int g[9]={1,2,3,4,5,6,7,8,0};
    for(int i=0;i<9;i++)
        if(a[i]!=g[i]) return 0;
    return 1;
}

int isVisited(int a[]){
    for(int i=0;i<vcount;i++){
        int same=1;
        for(int j=0;j<9;j++)
            if(visited[i][j]!=a[j]) same=0;
        if(same) return 1;
    }
    return 0;
}

void markVisited(int a[]){
    for(int i=0;i<9;i++)
        visited[vcount][i]=a[i];
    vcount++;
}

void DFS(int a[], int pos){

    print(a);

    if(isGoal(a)){
        printf("Goal reached!\n");
        return;
    }

    markVisited(a);

    int dx[4]={-3,3,-1,1};

    for(int i=0;i<4;i++){
        int np = pos + dx[i];

        if(np>=0 && np<9){
            int b[9];
            for(int j=0;j<9;j++) b[j]=a[j];

            b[pos]=b[np];
            b[np]=0;

            if(!isVisited(b))
                DFS(b,np);
        }
    }
}

int main(){
    int a[9]={1,2,3,4,0,6,7,5,8};
    DFS(a,4);
    return 0;
}
