#include <stdio.h>

int BOARD[9];   // 0 = blank, 1 = X, 2 = O

/* Display board */
void displayBoard()
{
    printf("\n");

    for(int i=0;i<9;i++)
    {
        char c;

        if(BOARD[i]==0) c=' ';
        else if(BOARD[i]==1) c='X';
        else c='O';

        printf(" %c ",c);

        if(i%3!=2) printf("|");

        if(i%3==2 && i!=8)
            printf("\n---+---+---\n");
    }

    printf("\n");
}

/* Convert board to decimal index (ternary representation) */
int boardToIndex()
{
    int index=0;
    int power=1;

    for(int i=0;i<9;i++)
    {
        index += BOARD[i]*power;
        power*=3;
    }

    return index;
}

/* Check win */
int checkWin(int p)
{
    if(BOARD[0]==p && BOARD[1]==p && BOARD[2]==p) return 1;
    if(BOARD[3]==p && BOARD[4]==p && BOARD[5]==p) return 1;
    if(BOARD[6]==p && BOARD[7]==p && BOARD[8]==p) return 1;

    if(BOARD[0]==p && BOARD[3]==p && BOARD[6]==p) return 1;
    if(BOARD[1]==p && BOARD[4]==p && BOARD[7]==p) return 1;
    if(BOARD[2]==p && BOARD[5]==p && BOARD[8]==p) return 1;

    if(BOARD[0]==p && BOARD[4]==p && BOARD[8]==p) return 1;
    if(BOARD[2]==p && BOARD[4]==p && BOARD[6]==p) return 1;

    return 0;
}

/* Check draw */
int checkDraw()
{
    for(int i=0;i<9;i++)
        if(BOARD[i]==0)
            return 0;

    return 1;
}

/* Computer simple move */
void computerMove()
{
    for(int i=0;i<9;i++)
    {
        if(BOARD[i]==0)
        {
            BOARD[i]=2;
            break;
        }
    }
}

/* Initialize board */
void initBoard()
{
    for(int i=0;i<9;i++)
        BOARD[i]=0;
}

int main()
{
    int move;

    initBoard();

    printf("Tic-Tac-Toe using BOARD and MOVETABLE concept\n");

    while(1)
    {
        displayBoard();

        printf("\nEnter your move (1-9): ");
        scanf("%d",&move);

        move--;

        if(move<0 || move>8 || BOARD[move]!=0)
        {
            printf("Invalid move\n");
            continue;
        }

        BOARD[move]=1;   // Player move

        int index = boardToIndex();
        printf("Current Board Index (ternary->decimal): %d\n", index);

        /* Check player win */
        if(checkWin(1))
        {
            displayBoard();
            printf("\nYou won!\n");
            break;
        }

        if(checkDraw())
        {
            displayBoard();
            printf("\nGame Draw!\n");
            break;
        }

        /* Computer move */
        computerMove();

        if(checkWin(2))
        {
            displayBoard();
            printf("\nComputer wins!\n");
            break;
        }

        if(checkDraw())
        {
            displayBoard();
            printf("\nGame Draw!\n");
            break;
        }
    }

    return 0;
}
