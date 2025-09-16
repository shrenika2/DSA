#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std ;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int , int >mpp;
        for (int i=0 ; i < n ; i++){
            mpp[nums[i]]++;
        } 
        for (auto it : mpp){
            if (it.second>(n/2)){
                return it.first;
            }
        }  
        return -1;    
        }
};