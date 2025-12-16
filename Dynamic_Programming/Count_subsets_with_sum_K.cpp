#include<iostream>
#include<vector>
using namespace std;
// memoization
class Solution {
public:
    int countSubsets(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // There's one way to make sum 0: the empty subset
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
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
    int countSubsets(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prev(target + 1, 0);
        prev[0] = 1; // There's one way to make sum 0: the empty subset

        for (int i = 0; i < n; i++) {
            vector<int> curr(target + 1, 0);
            curr[0] = 1; // There's one way to make sum 0: the empty subset
            for (int j = 0; j <= target; j++) {
                if (nums[i] <= j) {
                    curr[j] = prev[j - nums[i]] + prev[j];
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
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    int target = 10;
    int count = sol.countSubsets(nums, target);
    cout << "Number of subsets with sum " << target << " is: " << count << endl;
    return 0;
}