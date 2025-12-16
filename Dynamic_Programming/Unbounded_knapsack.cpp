#include<iostream>
#include<vector>
using namespace std;
// memoization approach
class Solution {
    vector <vector<int>> dp;
int solve(int i , int W , vector<int> &val , vector<int>&wt , int n){
    if (i >= n || W <= 0) return 0;
    int take = 0;
    if (wt[i] <= W){
        take = val[i] + solve(i , W - wt[i] , val , wt , n);
    }
    int notTake = solve(i + 1 , W , val , wt , n);
    return max(take, notTake);
}
public:
    int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt) {
        dp.resize(n , vector<int>(W + 1 , -1));
        return solve(0 , W , val , wt , n);
    }
};

// space optimization approach
class Solution2 {
public:
    int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt) {
        vector<int> dp(W + 1 , 0);
        for (int i = 0; i < n; i++){
            for (int w = wt[i]; w <= W; w++){
                dp[w] = max(dp[w] , val[i] + dp[w - wt[i]]);
            }
        }
        return dp[W];
    }
};
int main(){
    Solution2 sol;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int W = 8;
    int n = val.size();
    cout << sol.unboundedKnapsack(n , W , val , wt) << endl;
    return 0;
}