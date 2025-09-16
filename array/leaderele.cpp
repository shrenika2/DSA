#include <iostream>
#include <vector>
#include<set>
#include<algorithm>

using namespace std ;

class Solution_brute_force {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
// tc o(n^2) && sc =o(n)

class Solution_optimal {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int maxRight = INT_MIN;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] >= maxRight) {
                result.push_back(nums[i]);
                maxRight = nums[i];
            }
        }

        // Reverse the result to maintain original order
        reverse(result.begin(), result.end());
        return result;
    }
};//tc = o(n) && sc =o(n)
