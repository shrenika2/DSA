#include<iostream>
#include<vector>    
using namespace std;

// memoization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};

// space optimization
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        
        for (int i = 1; i < m; i++) {
            vector<int> curr(n, 1);
            for (int j = 1; j < n; j++) {
                curr[j] = prev[j] + curr[j-1];
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    cout << "Number of unique paths: " << sol.uniquePaths(m, n) << endl;
    return 0;
}