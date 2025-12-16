#include<iostream>
#include<vector>
using namespace std;

// memoization approach
class Solution {
public:
    const int mod = 1e9 + 7;
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notTake = f(ind - 1, target, arr, dp);
        int take = 0;
        if (arr[ind] <= target)
            take = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (take + notTake) % mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0) return 0;

        int target = (totalSum - d) / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
    }
};

// space optimization approach
class Solution1 {
public:
    const int mod = 1e9 + 7 ;
    int countPartitions(int n , int diff , vector<int>&arr){
        int totalSum = 0 ;
        for(int num : arr) totalSum += num ;
        if((totalSum - diff) < 0 || (totalSum - diff) % 2 != 0) return 0 ;
        int target = (totalSum - diff) / 2 ;
        vector<int> dp(target + 1 , 0) ;
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=target;j>=arr[i];j--){
                dp[j] = (dp[j] + dp[j-arr[i]]) % mod;
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sol;
    int n = 4;
    int d = 1;
    vector<int> arr = {1, 1, 2, 3};
    cout << sol.countPartitions(n, d, arr) << endl; // Output the number of partitions
    return 0;
}