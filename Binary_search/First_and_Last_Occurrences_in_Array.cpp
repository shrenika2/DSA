#include <iostream>
#include <vector>
using namespace std;


// Brute force 
// tc = o(n)
// sc = o(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int n= nums.size();
        for (int i=0 ; i < n ; i++){
            if (nums[i]==target){
                if (first == -1) first = i;
                last = i;
            }
        }
        return {first , last};
        
    }
};

// optimal solution 

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
    vector<int> searchRange(vector<int>& nums, int target) {
        int firsti = first(nums , target);
        int lasti = last(nums , target);
        return {firsti , lasti};
        
    }
};
