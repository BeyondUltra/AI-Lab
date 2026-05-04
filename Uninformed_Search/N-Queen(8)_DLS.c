void DLS(int r,int d){

    if(d==0) return;

    for(int c=0;c<N;c++){
        if(isSafe(r,c)){
            board[r]=c;
            DLS(r+1,d-1);
        }
    }
}
