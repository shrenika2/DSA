#include<iostream>
#include<vector>
using namespace std;
// memoization
class Solution {
public:
    vector<vector<bool>> dp;
    bool solve(int index, int target, vector<int>& nums) {
        if (target == 0) return true;
        if (index == 0) return nums[0] == target;

        if (dp[index][target] != -1) return dp[index][target];

        bool notTake = solve(index - 1, target, nums);
        bool take = false;
        if (nums[index] <= target) {
            take = solve(index - 1, target - nums[index], nums);
        }

        return dp[index][target] = take || notTake;
    }
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, vector<bool>(target + 1, -1));
        return solve(n - 1, target, nums);
    }
};
// space optimization
class Solution1 {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<bool> prev(target + 1, false);
        prev[0] = true; // sum 0 can always be formed with empty subset

        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true; // sum 0 can always be formed with empty subset
            for (int j = 1; j <= target; j++) {
                bool notTake = prev[j];
                bool take = false;
                if (nums[i] <= j) {
                    take = prev[j - nums[i]];
                }
                curr[j] = take || notTake;
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