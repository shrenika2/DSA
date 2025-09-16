#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std ;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
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
        if (n%2!=0){
            return nums3[n/2];
        }
        return ((double)(nums3[n/2]) + (double)(nums3[n/2 - 1])) / 2.0;
    }

};


class Solution{
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size() , n2 = b.size();
        int i = 0 ;
        int j = 0 ;
        int n = (n1 + n2);
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int cnt = 0 ;
        int ind1ele = -1 , ind2ele = -1;
        while (i<n1 && j<n2){
            if (a[i]<b[j]){
                if (cnt == ind1) ind1ele = a[i];
                if (cnt == ind2) ind2ele = a[i];
                cnt++;
                i++;

            }else {
                if (cnt == ind1) ind1ele = b[j];
                if (cnt == ind2) ind2ele = b[j];
                cnt++;
                j++;
            }
        }
        while (i < n1){
            if (cnt == ind1) ind1ele = a[i];
            if (cnt == ind2) ind2ele = a[i];
            cnt++ ;
            i++;
        }
        while (j<n2){
            if (cnt == ind1) ind1ele = b[j];
            if (cnt == ind2) ind2ele = b[j];
            cnt++ ;
            j++;
        }
        if (n%2==1){
            return (double)ind2ele;
        }
        return (double)((double)(ind1ele + ind2ele) / 2.0);


    }
};