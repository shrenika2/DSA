#include <iostream>
#include<algorithm>
#include <vector>

using namespace std ;

// brute force 
// tc = o(n)
// sc = o(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i= 0 ; i < n-1 ; i+=2){
            if (nums[i]!=nums[i+1]){
                return nums[i];
            }
            
        }
        return n-1;
    }
};

// bettter 
// tc = o(n)
// sc = o(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0 ;
        for (auto num : nums) ans^=num;
        return ans;
    }
};

// optimal solution
// tc = o(log n)
// sc = o(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        int low = 0 , high = n-2;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] == nums[mid ^ 1]){
                low = mid + 1 ;
            }else{
                high = mid - 1;
            }
        }
        return nums[low];

    }
};
