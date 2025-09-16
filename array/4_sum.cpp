#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std ;

// brute force 
///tc = o(n^4)
//sc = o(no, of quote) * 2

vector< vector <int>>  sum_subset(vector <int> &num , int target){
    int n = num.size();
    set<vector<int>> st;
    for (int i=0 ; i < n ; i++){
        for (int j=i+1 ; j < n; j++ ){
            for (int k=j+1 ; k < n ; k++ ){
                for (int l=k+1 ; l<n ; l++){
                    long long sum = num[i]+num[j];
                    sum += num[k];
                    sum += num[l];
                    if (sum==target){
                        vector <int > temp={num[i] , num[j] , num[k] , num[l]};
                        sort (temp.begin() , temp.end());
                        st.insert(temp);
                    }
                
                
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin() , st.end());
    return ans;
}



//better 
// tc =0(n^3 )* log (m)
// sc = o(n)+ o(no, of quote) * 2
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hash;
                for (int k = j + 1; k < n; k++) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k];//is to force integer promotion — making sure the entire sum is computed using 64-bit integers (long long) instead of 32-bit integers (int).
                    long long forth = 1LL * target - sum;

                    if (hash.find(forth) != hash.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)forth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    hash.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


// optimal 
// tc = o(n^3)
// sc = onky space used for the return the ans not for the solve the ques.== o(n0. of squads )
class Solution_optimal {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for (int i=0 ; i < n ; i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1 ;  j < n ; j++){
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while (k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if (sum == target){
                        vector <int > temp ={nums[i] , nums[j] , nums[k] , nums[l]};
                        
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k<l && nums[k]==nums[k-1]) k++;
                        while (k<l && nums[l]==nums[l+1]) l--;

                    }else if (sum< target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }

        

        return ans;
    }
};


