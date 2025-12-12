#include<iostream>
#include<vector>
using namespace std;
// memoization
class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true; // sum 0 can always be formed with empty subset
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};

// space optimization
class Solution1 {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<bool> prev(target + 1, false);
        prev[0] = true; // sum 0 can always be formed with empty subset

        for (int i = 1; i <= n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true; // sum 0 can always be formed with empty subset
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    curr[j] = prev[j - nums[i - 1]] || prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[target];
    }
};

int main() {
    Solution1 sol;
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    if (sol.isSubsetSum(nums, target)) {
        cout << "Found a subset with the given sum" << endl;
    } else {
        cout << "No subset with the given sum" << endl;
    }
    return 0;
}