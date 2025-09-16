#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std ;


// optimal 
// tc = O(n × log(sum of weights − max weight))
// sc = o(1)
class Solution {
public:
    int requireDays(vector<int>& weights, int capacity) {
        int days = 1, currentload = 0;
        for (int w : weights) {
            if (currentload + w > capacity) {
                days++;
                currentload = 0;
            }
            currentload += w;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int needed = requireDays(weights, mid);

            if (needed <= days) {
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
};
