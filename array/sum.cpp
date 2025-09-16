#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std ;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int > mpp;
        for (int i=0 ; i < n ; i++){
            int num= nums[i];
            int req = target-nums[i];
            if (mpp.find(req)!=mpp.end()){
                return {mpp[req] , i};
            }
            mpp[num]=i;
        }
        return {-1 , -1};
        }
};