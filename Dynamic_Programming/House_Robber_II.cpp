#include<iostream>
#include<vector>    
using namespace std;

// memoization
class Solution {
public:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> case1(nums.begin(), nums.end() - 1);

        vector<int> case2(nums.begin() + 1, nums.end());

        return max(robLinear(case1), robLinear(case2));
    }
};

// space optimization
class Solution1 {
public:
    int robliner(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0 ;
        if (n==1) return nums[0];

        int prev2 = 0 ;
        int prev1 = nums[0];

        for (int i=1 ; i < n ; i++){
            int pk = nums[i] + prev2;
            int npk = prev1;

            int curr = max(pk , npk);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }

    int rob(vector<int> &nums){
        int n = nums.size();
        if (n==1) return nums[0];

        vector<int> case1(nums.begin() , nums.end()-1);
        vector<int> case2(nums.begin()+1 , nums.end());

        return max(robliner(case1) , robliner(case2));
        
    }
};

int main (){
    int n ; 
    cin >> n ;

    vector<int> nums(n);
    for (int i = 0 ; i<n ; i++){
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.rob(nums);
    return 0;
   }
