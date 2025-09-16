#include <iostream>
#include <vector>

using namespace std ;

// brute force 
// tc = o(n^2)
// sc = o(1);


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mxpro = INT_MIN; // maximum product
        
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product *= nums[j];
                mxpro = max(mxpro, product);
            }
        }
        return mxpro;
    }
};


// optimal 
// tc = o(n)
// sc = o(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0]; 
        int mn = nums[0]; 
        int ans = nums[0]; 

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) 
                swap(mx, mn); 

            mx = max(nums[i], nums[i] * mx);
            mn = min(nums[i], nums[i] * mn); 

            ans = max(ans, mx);
        }
        return ans;
    }
};
