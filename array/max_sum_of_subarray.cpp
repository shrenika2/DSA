#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std ;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                mx = max(mx, sum);
            }
        }

        return mx;
    }
};//tc=o(n^2)


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int csum = 0;
        int mx=nums[0];
        for (int i=0 ; i < n ; i++){
            csum=max(nums[i] , csum+nums[i]);
            mx=max(csum , mx);
        }
        return mx;
        
    }
};// tc=o(n)
