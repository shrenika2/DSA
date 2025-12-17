#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;
// memoization approach
class Solution {
public:
    int dp[31][501];
    int solve(int i , int amount , vector<int> &coins){
        if (amount == 0) return 1;
        if (i >= coins.size() || amount < 0) return 0;
        if (dp[i][amount] != -1) return dp[i][amount];
        int take = solve(i , amount - coins[i] , coins);
        int notTake = solve(i + 1 , amount , coins);
        return dp[i][amount] = take + notTake;

    }
    int change(int amount, vector<int>& coins) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , amount , coins);
    }
};

// space optimization approach
class Solution2 {
public:

    int change (int amount , vector<int> &coins){
        vector<int> dp (amount + 1 , 0);
        dp[0] = 1;
        for (int coin : coins){
            for (int i = coin; i <= amount; i++){
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
int main(){
    Solution sol;
    vector <int> coins = {1,2,5};
    int amount = 5;
    cout << sol.change(amount , coins) << endl;
    return 0;
}