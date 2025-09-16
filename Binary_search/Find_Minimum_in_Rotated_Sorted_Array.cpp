#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;


// Brute force 
// tc = o(n)
// sc = o(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        int n = nums.size();
        for (int i=0 ; i < n ; i++){
            mini = min(mini , nums[i]);
        }
        return mini;
    }
};

// better 
// tc = o(n)
// sc = o(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = *min_element(nums.begin() , nums.end());
        return mini;
    }
    
};


// optimal
// tc = o(log n)
// sc = o(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
       int low = 0 ; 
       int high = n-1;
       while (low < high){
        int mid = (low + high)/2;
        if (nums[mid]>nums[high]){
            low = mid +1 ;
        }
        else {
            high=mid;
        }
       }
       return nums[low];
    }
    
};

