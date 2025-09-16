#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

// brute force 
// tc = o(m+n) + o(m+n)
// sc = o(m+n);
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num3(m + n);
        int left = 0, right = 0, index = 0;
        
        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                num3[index++] = nums1[left++];
            } else {
                num3[index++] = nums2[right++];
            }
        }
        while (left < m) {
            num3[index++] = nums1[left++];
        }
        while (right < n) {
            num3[index++] = nums2[right++];
        }
        
        // Copy back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = num3[i];
        }
    }
};

// optimal solution 1 
// tc = o(min(m , n)) + o(nlogn) + o(mlogm)
// sc = o(1) 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1, right = 0;
        
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--; right++;
            } else break;
        }
        
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        
        // Copy back nums2 into nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};

// optimal solution 2
// tc = log 2 (m+n) + o (m+n)
// sc = o(1)

class Solution {

private: 
    void swapIfGreater(vector<int>& nums1, int ind1, vector<int>& nums2, int ind2){
        if (nums1[ind1] > nums2[ind2]){
            swap(nums1[ind1], nums2[ind2]);
        }
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = (len + 1) / 2;  // same as (len / 2 + len % 2)
        
        while (gap > 0) {
            int left = 0, right = left + gap;
            
            while (right < len) {
                if (left < m && right < m) {
                    // Both pointers in nums1
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                } 
                else if (left < m && right >= m) {
                    // left in nums1, right in nums2
                    swapIfGreater(nums1, left, nums2, right - m);
                } 
                else {
                    // both in nums2
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }
                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap + 1) / 2;
        }

        // Copy nums2 back to nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};

