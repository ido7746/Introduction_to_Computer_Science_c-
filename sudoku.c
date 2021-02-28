#include<stdio.h>

#define N 3


void printBoard(int a[N*N][N*N])
{
    int i,j;
    for(i=0;i<N*N;i++){
        for(j=0;j<N*N;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n\n\n");
}


void resetArray(int* a)
{
    int i;
    for(int i=0; i<N*N;i++)
        a[i]=0;
}
int checkBoard(int board[N*N][N*N], int checkWin)
{
    int i, j, h, g;
    int checkArray[N*N];
    resetArray(checkArray);
    //check all the rows
    for(i=0;i<N*N;i++){
        for(j=0;j<N*N;j++){

            if((checkWin&&!board[i][j])||(board[i][j]!=0)&&(++checkArray[board[i][j]-1])>=2){
                return 0;
            }
        }
        resetArray(checkArray);
    }
    //check all the cols
    for(i=0;i<N*N;i++){
        for(j=0;j<N*N;j++){
            if(board[j][i]&&(++checkArray[board[j][i]-1])>=2)
                return 0;
        }
        resetArray(checkArray);
    }
    //check all the Squares
    for(g=0;g<N*N;g+=N){
        for(h=0;h<N*N;h+=N){
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    if(board[i+g][j+h]!=0&&++checkArray[board[i+g][j+h]-1]>=2)
                        return 0;
                }
            }
            resetArray(checkArray);
        }
    }
    return 1;

}


int solveSoduku(int board[N*N][N*N])
{
    int i, j, digit;
    int* a;
    for(i=0;i<N*N;i++){
        for(j=0;j<N*N;j++)
            if(board[i][j]==0){//check if it's empty
                for(digit=0;digit<N*N;digit++){//try all the digit's
                    board[i][j]=digit+1;
                    if(checkBoard(board,0)&&solveSoduku(board)){
                        return 1;
                    }
                }
                board[i][j]=0;
            }

        }

    return checkBoard(board,1);
}

int main()
{
    int board[N*N][N*N]={{6,3,7,2,9,8,1,0,4},
                         {2,9,5,0,7,1,3,8,6},
                         {8,1,4,5,3,6,2,0,0},
                         {3,0,6,7,0,4,9,1,8},
                         {0,8,1,9,0,2,4,3,5},
                         {5,4,9,1,8,0,7,6,2},
                         {4,7,8,3,1,5,6,2,9},
                         {1,5,2,6,4,9,0,0,3},
                         {9,6,3,8,2,7,5,4,1}};

    solveSoduku(board);
    printBoard(board);
    return 1;

}
