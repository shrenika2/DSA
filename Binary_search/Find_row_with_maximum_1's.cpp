#include <iostream>
#include <vector>
using namespace std;

// bs 
// tc = o(m+n)
// sc = o(1)

class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int maxRowIndex = -1;
        int j = n - 1; // Start from top-right corner

        for (int i = 0; i < m; i++) {
            while (j >= 0 && mat[i][j] == 1) {
                j--; // Move left for more 1s
                maxRowIndex = i; // Update max row index
            }
        }

        return maxRowIndex;
    }
};
