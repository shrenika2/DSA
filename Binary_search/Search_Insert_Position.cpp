#include <iostream>
#include <vector>

using namespace std ;
// tc =  
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0 , high = n-1;
        int ans = n ;
        while (low<=high){
            int mid = (low + high) /2;
            if (nums[mid]>=x){
                high = mid-1;
                ans=mid;
            }else {
                low = mid + 1;
            }
        }
        return ans;
        
    }
};