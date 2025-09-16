#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std ;

// optimal solution
// tc = O(nlogn+nlogdifference between the max and min stall positions) && sc = o(1)


class Solution {
public:

    bool CanReqCow(vector<int> &nums , int dist , int cows){
        int n = nums.size();
        int last = nums[0];
        int cntcow = 1;
        for (int i=1 ; i < n ; i++){
            if (nums[i]-last >= dist){
                cntcow++;
                last = nums[i];
            }
            if (cntcow >= cows) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int low = 1 ;
        int high = nums[n-1] - nums[0];
        while (low <= high){
            int mid = low + (high - low)/2;
            if (CanReqCow(nums , mid , k)==true){
                low = mid + 1;
            }else{
                high = mid - 1 ;
            }
        }
        return high;
        
    }
};