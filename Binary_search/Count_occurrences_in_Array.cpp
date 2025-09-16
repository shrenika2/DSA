#include <iostream>
#include <vector>
#include<algorithm>

using namespace std ;

// tc= o(log n)
// sc = o(1)

class Solution {
public:

    int first(vector<int>& nums, int target ){
        int first = -1 ;
        int low= 0 ;
        int n = nums.size();
        int high = n-1;
        while (low <= high){
            int mid = (low + high) /2;
            if (nums[mid]>=target) high = mid-1;
            else low = mid + 1;
            if (nums[mid]==target) first=mid;

        }
        return first;

    }
    int last(vector<int>& nums, int target ){
        int last = -1 ;
        int low= 0 ;
        int n = nums.size();
        int high = n-1;
        while (low <= high){
            int mid = (low + high) /2;
            if (nums[mid]<=target) low = mid+1;
            else high = mid - 1;
            if (nums[mid]==target) last=mid;

        }
        return last;

    }
    pair <int , int> searchRange(vector<int>& nums, int target) {
        int firsti = first(nums , target);
        int lasti = last(nums , target);
        return {firsti , lasti};
        
    }

    int count (vector<int> &arr , int target ){
        pair<int , int> ans = searchRange(arr , target );
            if (ans.first == -1 ) return 0;
            return ans.second - ans.first + 1;
        
    }
};

// stl based solution
class Solution {
public:
    int countOccurrences(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        return upper - lower;
    }
};