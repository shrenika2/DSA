#include <iostream>
#include <vector>
#include <set>
using namespace std ;
// Brute force 
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        set<int>st;
        for (int i=0 ; i < n1 ; i++){
            st.insert(nums1[i]);
        }
        for (int i=0 ; i < n2 ; i++){
            st.insert(nums2[i]);
        } 
        vector <int> temp;
        for (auto it : st){
            temp.push_back(it);
        } 
        return temp;      
    }
};

// optimal 
class Solution {
public:
    vector<int> unionArray(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        int i = 0, j = 0;
        vector<int> result;

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
            } else if (a[i] > b[j]) {
                if (result.empty() || result.back() != b[j]) {
                    result.push_back(b[j]);
                }
                j++;
            } else {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        while (i < n1) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }

        while (j < n2) {
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }

        return result;
    }
};
