#include <Iostream>
#include <vector>

using namespace std ;

// tc = o(2^n * n)
// sc = o(2^n * n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int mask=0 ; mask < (1<<n) ; mask++){
            vector <int > a;
            for (int i=0 ; i < n ; i++){
                if (mask & (1<<i)){
                    a.push_back(nums[i]);

                }
            }
            res.push_back(a);
        }
        return res ;
    }
};