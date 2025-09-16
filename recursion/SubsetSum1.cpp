#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

class Solution {
public:
    void func(int ind, int sum, vector<int>& arr, int n, vector<int>& sumsubSet) {
        if (ind == n) {
            sumsubSet.push_back(sum);
            return;
        }
        // pick the element
        func(ind + 1, sum + arr[ind], arr, n, sumsubSet);
        // do not pick the element (FIXED: increment ind)
        func(ind + 1, sum, arr, n, sumsubSet);
    }

    vector<int> sumsubSetall(vector<int> arr, int n) {
        vector<int> sumsubSet;
        func(0, 0, arr, n, sumsubSet);
        sort(sumsubSet.begin(), sumsubSet.end());
        return sumsubSet;
    }
};
