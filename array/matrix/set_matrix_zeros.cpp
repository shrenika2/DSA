#include <iostream>
#include <vector>
using namespace std ;

class Solution_optimal{
public:
    vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();       // rows
        int m = matrix[0].size();    // columns
        int col0 = 1;                // flag for first column

        // Step 1: Mark zeroes using first row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // mark the row
                    if (j != 0) {
                        matrix[0][j] = 0; // mark the column
                    } else {
                        col0 = 0; // column 0 needs to be zeroed
                    }
                }
            }
        }

        // Step 2: Set zeroes based on markers (excluding first row and col)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

        return matrix;
    }
};
