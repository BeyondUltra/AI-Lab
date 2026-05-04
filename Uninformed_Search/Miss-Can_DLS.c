void DLS(int m,int c,int boat,int d){

    printf("(M=%d C=%d d=%d)\n",m,c,d);

    if(d==0) return;

    int moves[5][2]={{1,0},{0,1},{1,1}};

    for(int i=0;i<3;i++){
        int nm = m - moves[i][0];
        int nc = c - moves[i][1];

        if(isValid(nm,nc))
            DLS(nm,nc,0,d-1);
    }
}
