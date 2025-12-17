#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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
            return dp[i][j] = max(lcs(i-1 , j , s1 , s2 , dp) , lcs(i , j-1 , s1 , s2 , dp));
        }
    } 
    string printLCS(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        lcs(n-1 , m-1 , s1 , s2 , dp);

        // reconstructing the LCS from the dp table
        int i = n - 1;
        int j = m - 1;
        string lcs_str = "";

        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                lcs_str += s1[i];
                i--;
                j--;
            } 
            else {
                if (i > 0 && dp[i-1][j] >= dp[i][j-1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        reverse(lcs_str.begin(), lcs_str.end());
        return lcs_str;
    }
};

// tabulation approach
class Solution1 {
public:
    string printLCS(string s1, string s2) {
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

        // reconstructing the LCS from the dp table
        int i = n;
        int j = m;
        string lcs_str = "";

        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                lcs_str += s1[i-1];
                i--;
                j--;
            } 
            else {
                if (dp[i-1][j] >= dp[i][j-1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        reverse(lcs_str.begin(), lcs_str.end());
        return lcs_str;
    }
};

// space optimization
class Solution2 {
public:
    string printLCS(string s1, string s2) {
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

        // reconstructing the LCS from the dp table
        int i = n;
        int j = m;
        string lcs_str = "";

        // We need to reconstruct the dp table for backtracking
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int ii = 1; ii <= n; ii++) {
            for (int jj = 1; jj <= m; jj++) {
                if (s1[ii-1] == s2[jj-1]) {
                    dp[ii][jj] = 1 + dp[ii-1][jj-1];
                } else {
                    dp[ii][jj] = max(dp[ii-1][jj], dp[ii][jj-1]);
                }
            }
        }

        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                lcs_str += s1[i-1];
                i--;
                j--;
            } 
            else {
                if (dp[i-1][j] >= dp[i][j-1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        reverse(lcs_str.begin(), lcs_str.end());
        return lcs_str;
    }
};

int main() {
    Solution sol;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "Longest Common Subsequence: " << sol.printLCS(s1, s2) << endl;
    return 0;
}