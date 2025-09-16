#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

// optimal 
// tc= o(log n)
// sc = o(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0 ;
        int high = arr.size() - 1 ;

        while (low <= high){
            int mid = low + (high - low)/2;
            int missing = arr[mid]-(mid+1);
            if (missing < k){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return low + k;// arr[high] + k - (arr[high]-high-1)
        
    }
};