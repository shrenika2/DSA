#include <iostream>
#include <vector>

using namespace std ;


// Brute force 
// tc = o(n)
// sc = o(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        if (n==1) {return 0;}
        if (n==2) {
            if (nums[0]>nums[1]){
                return 0;
            }else{
                return 1;
            }
        }
        if (nums[0]>nums[1]) return 0;
        if (nums[n-1]>nums[n-2]) return n-1;
        for (int i=1 ; i < n-1 ; i++ ){
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                ind = i;
            }
        }
        return ind;
    }
};

//optimal
// tc = o(log n)
// sc = o(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0 ; 
        int high = n-1;

        while (low < high){
            int mid = low + (high - low)/2;
            if (nums[mid]>nums[mid+1]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low ;
    }
};