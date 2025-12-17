#include<iostream>
#include<vector>
#include<string>
using namespace std;
// memorization approach
class Solution {
public: 
    int lcs(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp){
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + lcs(i-1 , j-1 , s1 , s2 , dp);
        }
        else {
            return dp[i][j] = max(lcs(i-1 , j , s1 , s2 , dp) , lcs(i , j-1 , s1 , s2 , dp));
        }
    } 
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return lcs(n-1 , m-1 , s1 , s2 , dp);
    }
};

// tabulation approach
class Solution1 {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

        for (int i=1 ; i <= n ; i++){
            for (int j=1 ; j <= m ; j++){
                if (s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

// space optimization
class Solution2 {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1 , 0);
        vector<int> curr(m+1 , 0);

        for (int i=1 ; i <= n ; i++){
            for (int j=1 ; j <= m ; j++){
                if (s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else {
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main (){
    Solution2 sol;
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Length of Longest Common Subsequence: " << sol.longestCommonSubsequence(s1 , s2) << endl;
    return 0;
}