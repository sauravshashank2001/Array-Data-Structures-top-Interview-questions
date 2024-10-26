#include<bits/stdc++.h>
using namespace std;


//brute force- Take another dummy matrix of n*n, and 
//then take the first row of the matrix and put it in the last column of the dummy matrix, 
//take the second row of the matrix, and put it in the second last column of the matrix and so.
void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    matrix=rotated;
}
//approach 2- optimal - take transpose and reverse ech row this you can get the rotated
 void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
        //transposing the matrix
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
        }
        //reversing each row of the matrix
        for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
        }
    }




int main(){
    vector<vector<int>> nums = {{1,0,1},{1,0,1},{1,0,1}};
    rotate(nums);
    
}