#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std ;

class Solution {
public:
    long long calculateTotalHour(vector<int>& piles, int hourly) {
        long long totalH = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalH += (piles[i] + hourly - 1) / hourly;  // integer ceiling
        }
        return totalH;
    }

    int findmx(vector<int>& piles) {
        return *max_element(piles.begin(), piles.end());
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findmx(piles);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHour(piles, mid);

            if (totalH <= h) {
                ans = mid;        // store the valid speed
                high = mid - 1;   // try to find smaller speed
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
