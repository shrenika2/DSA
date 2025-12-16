#include<iostream>
#include<vector>
using namespace std;
// memoization approach
class Solution {
    vector <int> dp;
public:
    int f(int amt , vector <int> & coins){
        if (amt == 0) return 0;
        if (amt < 0) return 1e9;
        if (dp[amt] != -1) return dp[amt];
        int mini = 1e9;
        for (int i = 0; i < coins.size(); i++){
            mini = min(mini , 1 + f(amt - coins[i] , coins));
        }
        return dp[amt] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1 , -1);
        int ans = f(amount , coins);
        if (ans == 1e9) return -1;
        return ans;
    }
};
// space optimaization approach
class Solution2 {
public:
    int coinChange(vector<int> & coins , int amount){
        vector<int> dp (amount +  1 , amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++){
            for (int coin : coins){
                if (coin <=i){
                    dp[i] = min (dp[i] , 1 + dp[i-coin]);
                }
            }
            return dp[amount] > amount ? -1 : dp[amount];
    }
}
};
int main(){
    Solution2 sol;
    vector <int> coins = {1,2,5};
    int amount = 11;
    cout << sol.coinChange(coins , amount) << endl;
    return 0;
}