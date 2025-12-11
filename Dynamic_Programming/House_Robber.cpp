#include<iostream>
#include<vector>    
using namespace std;

//memoization

class Solution {
public:
    int robutil(vector<int> & nums){
        int n = nums.size();

        if (n==1) return nums[0];

        vector<int> dp(n , -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);
        for (int i = 2 ; i<n ; i++){
            int pick = nums[i] + dp[i-2];
            int notpick = dp[i-1];

            dp[i] = max(pick , notpick);
        }
        return dp[n-1];
    }
};
//space optimization
class Solution1 {
public:
    int robutil(vector<int> & nums){
        int n = nums.size();

        if (n==1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0] , nums[1]);

        for (int i = 2 ; i<n ; i++){
            int pick = nums[i] + prev2;
            int notpick = prev1;

            int curr = max(pick , notpick);
            prev2 = prev1 ;
            prev1 = curr ;
        }
        return prev1;
    }
};

int main (){
    int n ; 
    cin >> n ;

    vector<int> nums(n);
    for (int i = 0 ; i<n ; i++){
        cin >> nums[i];
    }

    Solution1 obj;

    cout << obj.robutil(nums);
    return 0;
   }
