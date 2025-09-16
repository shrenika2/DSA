#include <iostream>
#include <vector >
#include <unordered_map>

using namespace std ;

class Solution_brute {
public:   
    int singleNumberBrute(vector<int>& nums) {
    int n = nums.size();

    // Loop through each element
    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count how many times nums[i] appears in the array
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }

        // If it appears only once, return it
        if (count == 1) {
            return nums[i];
        }
    }

    return -1; // In case no such element exists
}
};//tc = o(n*n) && sc = o(1)

class Solution_better {
public:   
    int singleNumberHashing(vector<int>& nums) {
    unordered_map<int, int> freq;  // Map to store frequency of each element

    // Count frequency of each number
    for (int num : nums) {
        freq[num]++;
    }

    // Find the number with frequency 1
    for (auto it : freq) {
        if (it.second == 1) {
            return it.first;
        }
    }

    return -1; // If no unique number is found
}
};// tc = sc = o(n)

class Solution_optimal {
public:   
    int singleNumberXOR(vector<int>& nums) {
    int xor_result = 0;

    // XOR all elements. Duplicate elements will cancel out.
    for (int num : nums) {
        xor_result ^= num;
    }

    // The result will be the number that appears only once
    return xor_result;
}
};



