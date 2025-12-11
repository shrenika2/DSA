#include<iostream>
#include<vector>
using namespace std;
// memoization 
class Solution {
public:
   int f(int n , vector<int> &dp){
    if (n<=1) return n ;
    if (dp[n]!=-1) return dp[n];

    return dp[n] = f(n-1 , dp) + f(n-2 , dp);

   }
};
// tabulation
class Solution1 {
public:
   int f(int n){
    vector<int> dp(n+1 , 0);
    dp[0] = 0 ;
    dp[1] = 1 ;

    for (int i = 2 ; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

   }
};
// space optimization
class Solution2 {
public:
   int f(int n){
    int prev2 = 0 ;
    int prev1 = 1 ;

    for (int i = 2 ; i<=n ; i++){
        int curr = prev1 + prev2;
        prev2 = prev1 ;
        prev1 = curr ;
    }
    return prev1 ;

   }
};
    
   int main (){
    int n ; 
    cin >> n ;

    vector<int> dp(n+1 , -1);
    Solution obj;

    cout << obj.f(n , dp);
    return 0;
   }