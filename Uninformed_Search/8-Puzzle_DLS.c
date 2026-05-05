#include <stdio.h>

int goal[9] = {1,2,3,4,5,6,7,8,0};

// -------- PRINT --------
void print(int a[]){
    printf("\n");
    for(int i=0;i<9;i++){
        printf("%d ",a[i]);
        if(i%3==2) printf("\n");
    }
}

// -------- GOAL CHECK --------
int isGoal(int a[]){
    for(int i=0;i<9;i++)
        if(a[i] != goal[i])
            return 0;
    return 1;
}

// -------- DLS --------
void DLS(int a[], int pos, int d){

    print(a);

    // goal check
    if(isGoal(a)){
        printf("Goal Found!\n");
        return;
    }

    // depth limit reached
    if(d == 0) return;

    int dx[4] = {-3, 3, -1, 1};

    for(int i=0;i<4;i++){

        int np = pos + dx[i];

        // -------- MOVE VALIDATION --------
        if(np < 0 || np >= 9) continue;

        // LEFT move check
        if(dx[i] == -1 && pos % 3 == 0) continue;

        // RIGHT move check
        if(dx[i] == 1 && pos % 3 == 2) continue;

        int b[9];

        // copy state
        for(int j=0;j<9;j++)
            b[j] = a[j];

        // swap blank
        b[pos] = b[np];
        b[np] = 0;

        // recursive call
        DLS(b, np, d-1);
    }
}

// -------- MAIN --------
int main(){

    int start[9] = {
        1,2,3,
        4,0,6,
        7,5,8
    };

    DLS(start, 4, 3); // start at index 4, depth limit 3

    return 0;
}
