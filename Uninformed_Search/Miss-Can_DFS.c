#include <stdio.h>

int visited[4][4][2];

int isValid(int m,int c){
    if(m<0||c<0||m>3||c>3) return 0;
    if(m>0 && m<c) return 0;
    if((3-m)>0 && (3-m)<(3-c)) return 0;
    return 1;
}

void DFS(int m,int c,int boat){

    printf("(M=%d C=%d Boat=%d)\n",m,c,boat);

    if(m==0 && c==0){
        printf("Goal reached!\n");
        return;
    }

    visited[m][c][boat]=1;

    int moves[5][2]={{1,0},{2,0},{0,1},{0,2},{1,1}};

    for(int i=0;i<5;i++){
        int nm,nc,nb;

        if(boat==1){
            nm=m-moves[i][0];
            nc=c-moves[i][1];
            nb=0;
        }else{
            nm=m+moves[i][0];
            nc=c+moves[i][1];
            nb=1;
        }

        if(isValid(nm,nc) && !visited[nm][nc][nb])
            DFS(nm,nc,nb);
    }
}

int main(){
    DFS(3,3,1);
    return 0;
}
