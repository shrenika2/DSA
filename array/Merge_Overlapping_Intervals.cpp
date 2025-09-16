#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;


// brute force 
// tc =o(nlog(n) ) + o(2n)
//sc = o(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans ;
        for (int i=0 ; i < n ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (!ans.empty() && end <= ans.back()[1]){
                continue;
            }
            for (int j=i+1 ; j <n ;j++){
                if (intervals[j][0]<=end){
                    end=max(end , intervals[j][1]);
                }else{
                    break;
                }
            }
            ans.push_back({start , end});
        }
        return ans;
    }
};


// optimal
// tc = o(nlogn) +o(n)
// sc = o(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort (arr.begin() , arr.end());
        vector <vector<int>> ans;
        for (int i=0 ; i < n ; i++){
            if (ans.empty() || arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);
            }else {
                ans.back()[1] = max(ans.back()[1] , arr[i][1]);
            }
        }return ans;
        
    }
};
 