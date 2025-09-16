#include <iostream>
#include<vector>

using namespace std ;

//brute force
// tc = o(n^2)
// sc = o(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0 ;
        for (int i= 0 ; i < n-1 ; i++){
            for (int j=i+1 ; j < n ; j++){
                if (i<j  &&  nums[i] > 2LL * nums[j]){
                    cnt++;
                }
            }
        }
        return cnt ;
        
    }
};