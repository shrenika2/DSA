#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std ;

// optimal 
// tc = O(n * log((max gap)/eps))
// sc = 

class Solution {
public:
    bool isPossible(vector<int>& arr, int k, double dist) {
        int cnt = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            double gap = arr[i+1] - arr[i];
            cnt += (int)(gap / dist);
        }
        return cnt <= k;
    }

    double minimiseMaxDistance(vector<int>& arr, int k) {
        double low = 0.0;
        double high = arr.back() - arr.front();
        double eps = 1e-6;

        while (high - low > eps) {
            double mid = low + (high - low) / 2.0;
            if (isPossible(arr, k, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return low;
    }
};
