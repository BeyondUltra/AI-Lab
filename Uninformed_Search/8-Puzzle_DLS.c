void DLS(int a[], int pos, int d){

    print(a);

    if(d==0) return;

    int dx[4]={-3,3,-1,1};

    for(int i=0;i<4;i++){
        int np=pos+dx[i];

        if(np>=0 && np<9){
            int b[9];
            for(int j=0;j<9;j++) b[j]=a[j];

            b[pos]=b[np];
            b[np]=0;

            DLS(b,np,d-1);
        }
    }
}
