#include<iostream>
#include<vector>
#include<string>
using namespace std;
//memoirization approach
class Solution {    
public: 
    int lcs(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp){
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + lcs(i-1 , j-1 , s1 , s2 , dp);
        }
        else {
            return dp[i][j] = 0;
        }
    } 
    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxLength = max(maxLength, lcs(i, j, s1, s2, dp));
            }
        }
        return maxLength;
    }
};
// tabulation approach
class Solution1 {
public:
    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        int maxLength = 0;

        for (int i=1 ; i <= n ; i++){
            for (int j=1 ; j <= m ; j++){
                if (s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLength = max(maxLength, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxLength;
    }
};
// space optimization
class Solution2 {
public:
    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1 , 0);
        vector<int> curr(m+1 , 0);
        int maxLength = 0;

        for (int i=1 ; i <= n ; i++){
            for (int j=1 ; j <= m ; j++){
                if (s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    maxLength = max(maxLength, curr[j]);
                }
                else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return maxLength;
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "abfce";
    
    Solution sol;
    cout << "Length of Longest Common Substring: " << sol.longestCommonSubstring(s1, s2) << endl;

    return 0;
}