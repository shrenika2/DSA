#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
#include<unordered_set>

using namespace std ;

class Solution_brute_force {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int longest = 1;

        for (int i = 0; i < n; i++) {
            int current = nums[i];
            int count = 1;

            // Check if the next numbers exist
            while (find(nums.begin(), nums.end(), current + 1) != nums.end()) {
                current += 1;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};//tc==o(n^2)  && sc==o(1)

class Solution_better {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());
        int longest = 1, count = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) continue; // Skip duplicates
            else if (nums[i] == nums[i - 1] + 1) count++;
            else count = 1;

            longest = max(longest, count);
        }

        return longest;
    }
};//tc==o(nlogn) && sc == o(1) (excluding sort).

class Solution_optimal {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only start counting from the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int count = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};// tc == o(n) && sc==o(n)

