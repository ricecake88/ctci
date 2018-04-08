// 1.7MatrixZero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

void turnZero(int *matrix[], const int row, const int col) {

  int *hasZeroRow = (int *) malloc(sizeof(int)*row);
  int *hasZeroCol = (int *) malloc(sizeof(int)*col);
  memset(hasZeroRow, 0, sizeof(int)*row);
  memset(hasZeroCol, 0, sizeof(int)*col);

  int x, y = 0;
  for (x = 0; x < row; x++) {
    for (y = 0; y < row; y++) {
      if (matrix[x][y] == 0) {
        if (!(hasZeroRow[x] || hasZeroCol[y])) {
          hasZeroRow[x] = 1;
          hasZeroCol[y] = 2;
          for (int i=0; i < row; i++) {
            matrix[x][i] = 0;
          }
          for (int j=0; j < col; j++) {
            matrix[j][y] = 0;
          }
        }
      }
    }
  }

  for (x = 0; x < row; x++) {
    for (y = 0; y < col; y++) {
      printf("%i ",matrix[x][y]);
    }
    printf("\n");
  }
}

int main()
{
  int matrix[3][2] = {
    {1, 0},
    {3, 4},
    {5, 6}
  };
  const int row = 3;
  const int col = 2;

  int *hasZeroRow = (int *) malloc(sizeof(int)*row);
  int *hasZeroCol = (int *) malloc(sizeof(int)*col);
  memset(hasZeroRow, 0, sizeof(int)*row);
  memset(hasZeroCol, 0, sizeof(int)*col);

  int x, y = 0;
  for (x = 0; x < row; x++) {
    for (y = 0; y < row; y++) {
      if (matrix[x][y] == 0) {
        if (!(hasZeroRow[x] || hasZeroCol[y])) {
          hasZeroRow[x] = 1;
          hasZeroCol[y] = 1;
          for (int i=0; i < col; i++) {
            matrix[x][i] = 0;
          }
          for (int j=0; j < row; j++) {
            matrix[j][y] = 0;
          }
        }
      }
    }
  }

  for (x = 0; x < row; x++) {
    for (y = 0; y < col; y++) {
      printf("%i ",matrix[x][y]);
    }
    printf("\n");
  }
    return 0;
}

