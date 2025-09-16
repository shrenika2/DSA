#include <iostream>
#include <vector>

using namespace std ;

// tc = o(n)
// sc = o(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =  0 ;
        for (auto it : nums){
            ans ^=it;
        }
        return ans ;
        
    }
};
