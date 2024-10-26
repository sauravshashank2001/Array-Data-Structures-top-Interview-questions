#include<bits/stdc++.h>
using namespace std;


/*
Problem Statement: Given a matrix if an element in the matrix is 0
then you will have to set its entire column and row to 0 and then return the matrix.

Input:
 matrix=[[1,1,1],[1,0,1],[1,1,1]]

Output:
 [[1,0,1],[0,0,0],[1,0,1]]
 */


//approach1 - brute force 

/*
First, we will use two loops(nested loops) to traverse all the cells of the matrix.
If any cell (i,j) contains the value 0, we will mark 
all cells in row i and column j with -1 except those which contain 0.
We will perform step 2 for every cell containing 0.
Finally, we will mark all the cells containing -1 with 0.

//ONLY IF -1 IS NOT PReSeNT. 

 */
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix1(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


//approach2 
/**
 * First, we will declare two arrays: a row array of 
 * size N and a col array of size M and both are initialized with 0.
Then, we will use two loops(nested loops) to 
traverse all the cells of the matrix.
If any cell (i,j) contains the value 0,
 we will mark ith index of row array i.e.
  row[i] and jth index of col array col[j] as 1.
   It signifies that all the elements in the ith row and jth column will be 0 in the final matrix.
We will perform step 3 for every cell containing 0.
Finally, we will again traverse the entire matrix and we 
will put 0 into all the cells (i, j) for which either row[i] or col[j] is marked as 1.
Thus we will get our final matrix.
 * 
 */

vector<vector<int>> zeroMatrix2(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


int main(){
    vector<vector<int>> nums = {{1,0,1},{1,0,1},{1,0,1}};
    vector<vector<int>> zeroMatrixFinal;
    zeroMatrixFinal = zeroMatrix(nums);
    
}