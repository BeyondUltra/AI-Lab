#include <stdio.h>

int used[10] = {0};   // track used digits
int S,E,N,D,M,O,R,Y;

// check full equation
int isValid(){
    int send = 1000*S + 100*E + 10*N + D;
    int more = 1000*M + 100*O + 10*R + E;
    int money=10000*M+1000*O+100*N+10*E+Y;

    return send + more == money;
}

// recursive CSP solver
void solve(int pos){
    if(pos == 8){  // all variables assigned
        if(isValid()){
            printf("SEND=%d MORE=%d MONEY=%d\n",
                   1000*S+100*E+10*N+D,
                   1000*M+100*O+10*R+E,
                   10000*M+1000*O+100*N+10*E+Y);
        }
        return;
    }

    for(int d=0; d<=9; d++){
        if(!used[d]){

            // assign variable based on position
            if(pos==0){ if(d==0) continue; S=d; }
            if(pos==1){ E=d; }
            if(pos==2){ N=d; }
            if(pos==3){ D=d; }
            if(pos==4){ if(d==0) continue; M=d; }
            if(pos==5){ O=d; }
            if(pos==6){ R=d; }
            if(pos==7){ Y=d; }

            used[d] = 1;

            solve(pos+1);   // go deeper

            used[d] = 0;    // backtrack
        }
    }
}

int main(){
    solve(0);
    return 0;
}
