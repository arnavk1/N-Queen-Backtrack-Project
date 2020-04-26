#include <stdio.h>
#include<stdbool.h>
int N;
void printBoard(int board[N][N]){
  int i,j;
  for(i=0; i<N; i++){
    for(j=0; j<N;j++){
      printf("%d ", board[i][j] );
    }
    printf("\n");
  }
}

bool checkSafety(int board[N][N], int row, int col){
  int i,j;
  //check left side
  for(i = 0; i < col; i++)
    if(board [row] [i])
      return false;
//check upper diagonal on left
  for(i = row, j = col; i >= 0 && j >= 0; --i , --j)
    if(board[i][j])
      return false;
//check lower diagonal on left
  for(i = row , j = col; i<N && j >= 0; ++i , --j)
    if(board[i] [j])
      return false;

  return true;
}

bool   placeQueen(int board[N][N], int col){
  int i;
  if(col >= N)
    return true;

    for(i = 0; i < N; i++){
      if(checkSafety(board, i, col)){

          board [i] [col] = 1;

          if(placeQueen(board, col + 1))
            return true;

            board[i][col] = 0; //backtrack
      }
    }
  return false;
}

bool solveBoard (int N) {


  int board [10] [10] = {0};

  if(placeQueen(board, 0) == false){
    printf("Solution does not exist");
    return false;
  }
  printBoard(board);
  return true;
}


int main () {
  printf("Enter size of chessboard <= 10\n");
  scanf("%d", &N);
  if(N > 10){
    printf("Wrong Input try Again");
    exit(0);
  }
  solveBoard(N);
  return 0;
}
