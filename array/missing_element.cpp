#include <iostream>
#include <vector>
using namespace std ;

class Solution_optimal_sum {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int s2 = 0;
        for (int i = 0; i < n; i++) {
            s2 += nums[i];
        }
        return sum - s2;
    }
};// tc = o(n) && sc = o(1)

class Solution_XOR {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();

        // XOR from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR all elements in the array
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];
        }

        // Missing number is the XOR of the above two
        return xor1 ^ xor2;
    }
};// tc = o(n) && sc = o(1)


class Solution_brute {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();  // Total number of elements present (i.e., n elements from 0 to n, one is missing)

        for (int i = 0; i <= n; i++) {  // We need to check all numbers from 0 to n inclusive
            int flag = 0;  // Flag to check if 'i' exists in the array

            for (int j = 0; j < n; j++) {  // Loop through the array to search for 'i'
                if (nums[j] == i) {  // If 'i' is found in the array
                    flag = 1;  // Set flag to 1 (found)
                    break;     // No need to search further
                }
            }

            if (flag == 0) {
                return i;  // If 'i' was not found in the array, it's the missing number
            }
        }

        return -1;  // Should never reach here if input is valid
    }
};
// tc = o(n*n)  sc=o(1)


class Solution_hashing {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);  // hash array of size n+1 initialized with 0

        // Mark presence of each number in nums
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }

        // Find the missing number
        for (int i = 0; i <= n; i++) {
            if (hash[i] == 0) {
                return i;
            }
        }

        return -1;  // Should never reach here for valid input
    }
};// tc = o(2n)  && sc = o(n)


