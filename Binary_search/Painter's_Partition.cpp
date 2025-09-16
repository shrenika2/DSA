#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std ;

// optimal solution 
// tc = O(n * log(sum(C) - max(C)))
// sc=o(1)

#define MOD 10000003

class Solution {
public:
    int painters(vector<int> &nums, int limit) {
        int painter = 1;
        long long painter_cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (painter_cnt + nums[i] <= limit) {
                painter_cnt += nums[i];
            } else {
                painter++;
                painter_cnt = nums[i];
            }
        }
        return painter;
    }

    int paint(int A, int B, vector<int>& C) {
        long long low = *max_element(C.begin(), C.end());
        long long high = accumulate(C.begin(), C.end(), 0LL);

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (painters(C, mid) > A) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (low * B) % MOD;
    }
};
