#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// memoization

class Solution {
public:
    int solve(int i , int j , vector<vector<int>>&t , vector<vector<int>> &dp){
        int n = t.size();

        if (i==n-1) return t[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int down = t[i][j] + solve(i+1 , j , t , dp);
        int diag = t[i][j] + solve(i+1 , j+1 , t , dp);
        return dp[i][j] = min(down , diag);
    }
    int minimumTotal(vector<vector<int>> & triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(0 , 0 , triangle , dp);

    }
};

// space optimization
class Solution1 {
public:
    int minimmunTotal(vector<vector<int>> & triangle){
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for (int i=n-2 ; i >=0 ; i--){
            for (int j=0 ; j <= i ; j++){
                dp[j] = triangle[i][j] + min(dp[j] , dp[j+1]);
            }
        }
        return dp[0];
    }
};

int main (){
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << "Minimum Path Sum in Triangle: " << sol.minimumTotal(triangle) << endl;

    Solution1 sol1;
    cout << "Minimum Path Sum in Triangle (Space Optimized): " << sol1.minimmunTotal(triangle) << endl;

    return 0;
}
