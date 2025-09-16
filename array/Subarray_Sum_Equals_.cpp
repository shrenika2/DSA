#include <iostream>
#include <map>
#include <vector>

using namespace std ;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>mpp;
        mpp[0]=1;
        int n = nums.size();
        int count=0;
        int prefix=0;
        for (int i=0 ; i < n ; i++){
            prefix+=nums[i];
            int remove=prefix-k;
            count+=mpp[remove];
            mpp[prefix]+=1;
            
        }
        return count;
        
    }
};