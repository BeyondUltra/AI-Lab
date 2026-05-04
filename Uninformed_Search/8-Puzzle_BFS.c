#include <stdio.h>
#include <string.h>

#define MAX 10000   // maximum number of states in queue

// Structure to store each puzzle state
typedef struct{
    int mat[3][3];  // 3x3 puzzle
    int x, y;       // position of blank (0)
}State;

// Queue for BFS
State queue[MAX];
int front=0, rear=0;

// Visited states stored as strings
char visited[MAX][10];
int vcount=0;

// Goal state
int goal[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

// Function to print puzzle
void printBoard(int mat[3][3]){
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Convert matrix into string (for visited checking)
// Example:
// 1 2 3
// 4 0 6   → "123406758"
// 7 5 8
void encode(int mat[3][3], char str[]){
    int k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            str[k++] = mat[i][j] + '0'; // convert int → char
    str[k]='\0';
}

// Check if state already visited
int isVisited(char str[]){
    for(int i=0;i<vcount;i++){
        if(strcmp(visited[i], str)==0)
            return 1; // already visited
    }
    return 0;
}

// Mark state as visited
void markVisited(char str[]){
    strcpy(visited[vcount++], str);
}

// Check if current state = goal state
int isGoal(int mat[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(mat[i][j]!=goal[i][j])
                return 0;
    return 1;
}

// Copy matrix a → b
void copy(int a[3][3], int b[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            b[i][j]=a[i][j];
}

// BFS function
void BFS(int start[3][3], int x, int y){

    State first;

    // Initialize first state
    copy(start, first.mat);
    first.x = x;
    first.y = y;

    queue[rear++] = first; // push into queue

    char str[10];

    // Mark start as visited
    encode(start, str);
    markVisited(str);

    // BFS loop
    while(front < rear){

        // Remove from queue (FIFO)
        State cur = queue[front++];

        // Print current state
        printBoard(cur.mat);

        // Check if goal reached
        if(isGoal(cur.mat)){
            printf("\nGoal Reached!\n");
            return;
        }

        // Possible movements of blank (UP, DOWN, LEFT, RIGHT)
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int i=0;i<4;i++){

            int nx = cur.x + dx[i]; // new x
            int ny = cur.y + dy[i]; // new y

            // Check valid move inside grid
            if(nx>=0 && nx<3 && ny>=0 && ny<3){

                State next;

                // Copy current state
                copy(cur.mat, next.mat);

                // Swap blank (0) with adjacent tile
                next.mat[cur.x][cur.y] = next.mat[nx][ny];
                next.mat[nx][ny] = 0;

                // Update blank position
                next.x = nx;
                next.y = ny;

                // Convert to string
                encode(next.mat, str);

                // If not visited, add to queue
                if(!isVisited(str)){
                    markVisited(str);
                    queue[rear++] = next;
                }
            }
        }
    }
}

// Main function
int main(){

    // Initial state
    int start[3][3] = {
        {1,2,3},
        {4,0,6},
        {7,5,8}
    };

    printf("8 PUZZLE USING BFS (WITH VISITED)\n");

    // Starting blank position = (1,1)
    BFS(start,1,1);

    return 0;
}
