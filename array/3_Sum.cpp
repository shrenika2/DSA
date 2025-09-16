#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std ;

// brute force 
// tc = o(n^3) + log(no.of unique triplets)
// sc = 2 * o(no. of triplets)

vector< vector <int>>  sum_subset(vector <int> &num){
    int n = num.size();
    set<vector<int>> st;
    for (int i=0 ; i < n ; i++){
        for (int j=i+1 ; j < n; j++ ){
            for (int k=j+1 ; k < n ; k++ ){
                if (num[i]+num[j]+num[k]==0){
                    vector <int> temp={num[i] , num[j] , num[k]};
                    sort (temp.begin() , temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin() , st.end());
    return ans;
}

// better solution
// tc = 
// sc = 

vector <vector <int>> sum_subset_better( vector <int> & a){
    int n = a.size();
    set<vector<int>> st ;
    //sort (a.begin() , a.end());
    for (int i=0 ; i < n ; i++){
        unordered_set<int> hash;
        for (int j=i+1 ; j < n ; j++){
            int third = -(a[i]+a[j]);
            if (hash.find(third)!= hash.end()){
            vector <int > temp={a[i] , a[j] , third};
            sort(temp.begin() , temp.end());
            st.insert(temp);
            }
            hash.insert(a[j]);
        }
       
    }
    vector <vector<int>> ans(st.begin() , st.end());
    return ans ;
}

// optimal solution 
// tc = nlog(n) + o(n*n)
// sc = o(no. of unique triplets )

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;  // Skip duplicates
                    while (j < k && nums[k] == nums[k + 1]) k--;  // Skip duplicates
                }
            }
        }
        return ans;
    }
};
