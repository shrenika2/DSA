#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std ;

// optimal solution
// tc = O(log(sumPages−maxBook))
// sc = o(1)

class Solution {
public:
    int array_sum(vector<int>& nums, int limit) {
        int subarray = 1;
        int sum_subarray = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum_subarray + nums[i] <= limit) {
                sum_subarray += nums[i];
            } else {
                subarray++;
                sum_subarray = nums[i];
            }
        }
        return subarray;
    }

    int splitArray(vector<int>& nums, int k) {
        if (k > nums.size()) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (array_sum(nums, mid) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
