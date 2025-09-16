#include <iostream>
#include<algorithm>
#include <vector>
using namespace std ;


// tc = o(log n)
// sc = o(1)
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
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
       return low;
    }
};