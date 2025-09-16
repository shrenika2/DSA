#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;

// brute => generate all possible permutation , linear search , next permutation

// next_permutation(a.begin() , a,end()) => stl

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If not found, the array is in descending order; reverse it
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element greater than nums[index] from the end
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse the part after index to get the next smallest permutation
        reverse(nums.begin() + index + 1, nums.end());
    }
};
