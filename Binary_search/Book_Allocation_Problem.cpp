#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std ;

// optimal solution
// tc = O(log(sumPages−maxBook))
// sc = o(1)

class Solution {
public:
    int total_student(vector<int> &nums, int pages) {
        int student = 1;
        int student_pages = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (student_pages + nums[i] <= pages) {
                student_pages += nums[i];
            } else {
                student++;
                student_pages = nums[i];
            }
        }
        return student;
    }

    int findPages(vector<int> &nums, int m) {
        if (m > nums.size()) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (total_student(nums, mid) > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
