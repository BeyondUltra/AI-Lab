void DLS(int x,int y,int d){

    if(x<0||y<0||x>=R||y>=C||maze[x][y]==1)
        return;

    printf("(%d,%d) depth=%d\n",x,y,d);

    if(d==0) return;

    DLS(x-1,y,d-1);
    DLS(x+1,y,d-1);
    DLS(x,y-1,d-1);
    DLS(x,y+1,d-1);
}
