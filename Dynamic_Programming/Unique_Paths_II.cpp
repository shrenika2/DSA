#include<iostream>
#include<vector>    
using namespace std;

// memoization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) return 0;
        
        dp[0][0] = 1; 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; 
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j]; // From top
                    if (j > 0) dp[i][j] += dp[i][j-1]; // From left
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};

// space optimization
class Solution1 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m , 0);

        dp[0]=(grid[0][0]==1 ? 0 : 1);

        for (int i=0 ; i < n ; i++){
            for (int j=0 ; j < m ;j++){
                if (grid[i][j]==1){
                    dp[j]=0;
                }else if (j>0){
                    dp[j]=dp[j]+dp[j-1];
                }
            }
        }
        return dp[m-1];
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << "Number of unique paths with obstacles: " << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}