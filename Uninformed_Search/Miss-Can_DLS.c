#include <stdio.h>

int visited[10][10][2] = {0};

// -------- VALIDITY CHECK --------
int isValid(int m, int c){
    int mr = 3 - m; // right side missionaries
    int cr = 3 - c; // right side cannibals

    // check bounds
    if(m < 0 || c < 0 || m > 3 || c > 3)
        return 0;

    // missionaries eaten on left
    if(m > 0 && m < c)
        return 0;

    // missionaries eaten on right
    if(mr > 0 && mr < cr)
        return 0;

    return 1;
}

// -------- DLS --------
void DLS(int m, int c, int boat, int d){

    printf("(M=%d C=%d Boat=%d Depth=%d)\n", m, c, boat, d);

    // goal: all moved to right side
    if(m == 0 && c == 0){
        printf("Goal reached!\n");
        return;
    }

    if(d == 0) return;

    if(visited[m][c][boat]) return;
    visited[m][c][boat] = 1;

    int moves[5][2] = {
        {1,0}, {0,1}, {1,1}, {2,0}, {0,2}
    };

    for(int i=0;i<5;i++){

        int nm, nc;

        if(boat == 1){ // boat on LEFT → go to RIGHT
            nm = m - moves[i][0];
            nc = c - moves[i][1];
        }
        else{ // boat on RIGHT → come back to LEFT
            nm = m + moves[i][0];
            nc = c + moves[i][1];
        }

        if(isValid(nm, nc)){
            DLS(nm, nc, 1 - boat, d-1); // toggle boat
        }
    }

    // backtrack
    visited[m][c][boat] = 0;
}

// -------- MAIN --------
int main(){
    DLS(3,3,1,10); // start: all on left, boat on left
    return 0;
}
