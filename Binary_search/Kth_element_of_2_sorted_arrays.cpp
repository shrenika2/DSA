#include <iostream>
#include <vector>

using namespace std ;

class Solution {
public:
    int kthElement(vector<int> &nums1, vector<int>& nums2, int k) {
      int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>nums3;
        int i = 0 ;
        int j = 0 ;
        while (i<  n1 && j<n2){
            if (nums1[i]<nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        while (i<n1) nums3.push_back(nums1[i++]);
        while (j<n2) nums3.push_back(nums2[j++]);
        int n = n1+n2;
        
            return nums3[k-1];
        
        
    }
  
};