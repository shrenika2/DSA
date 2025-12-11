#include<iostream>
#include<vector>    
using namespace std;

//memorization
class Solution {
public:
    int frogJump(vector<int> &heights){
        int n = heights.size();
        vector<int> dp(n);

        dp[0]=0;
        if (n>1){
            dp[1] = abs(heights[1]-heights[0]);
        }
        for (int i = 2 ; i<n ; i++){
            int jumpOne = dp[i-1] + abs(heights[i]-heights[i-1]);
            int jumpTwo = dp[i-2] + abs(heights[i]-heights[i-2]);

            dp[i] = min(jumpOne , jumpTwo);
        }
        return dp[n-1];
    }
};

//space optimization
class Solution1 {
public:
    int frogJump(vector<int> &heights){
        int n = heights.size();

        int prev2 = 0 ;
        int prev1 = abs(heights[1]-heights[0]);

        for (int i = 2 ; i<n ; i++){
            int jumpOne = prev1 + abs(heights[i]-heights[i-1]);
            int jumpTwo = prev2 + abs(heights[i]-heights[i-2]);

            int curr = min(jumpOne , jumpTwo);
            prev2 = prev1 ;
            prev1 = curr ;
        }
        return prev1;
    }
};

int main (){
    int n ; 
    cin >> n ;

    vector<int> heights(n);
    for (int i = 0 ; i<n ; i++){
        cin >> heights[i];
    }

    Solution1 obj;

    cout << obj.frogJump(heights);
    return 0;
   }