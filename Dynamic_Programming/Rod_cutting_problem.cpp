#include<iostream>
#include<vector>
#include<climits>

using namespace std;
// memoization approach
class Solution {
    int cutrod(int n , vector<int> &price , vector<int> &dp){
        if (n <= 0) return 0;
        if (dp[n] != -1) return dp[n];
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++){
            maxi = max(maxi , price[i] + cutrod(n - i - 1 , price , dp));
        }
        return dp[n] = maxi;
    }
public:
    int cutRod(vector<int> &price, int n) {
        vector<int> dp(n + 1 , -1);
        return cutrod(n , price , dp);
    }   
};
// space optimization approach
class Solution2 {
public:
    int cutRod(vector<int> &price, int n) {
        vector<int> dp(n + 1 , 0);
        for (int len = 1; len <= n; len++){
            int maxi = INT_MIN;
            for (int cut = 0; cut < len; cut++){
                maxi = max(maxi , price[cut] + dp[len - cut - 1]);
            }
            dp[len] = maxi;
        }
        return dp[n];
    }
};

int main(){
    Solution2 sol;
    vector<int> price = {1,5,8,9,10,17,17,20};
    int n = price.size();
    cout << sol.cutRod(price , n) << endl;
    return 0;
}