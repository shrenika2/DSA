#include<iostream>
#include<vector>
using namespace std;
// memoization
class Solution {
public:
    int R , C ;
    vector<vector<vector<int>>> dp ;

    int solve(int i , int j1 , int j2 , vector<vector<int>>& grid){
        // base case
        if(j1 < 0 || j1 >= C || j2 < 0 || j2 >= C) return -1e8 ;
        if(i == R-1){
            if(j1 == j2) return grid[i][j1] ;
            else return grid[i][j1] + grid[i][j2] ;
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2] ;

        int maxi = -1e8 ;
        // explore all paths
        for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
            for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                int value = 0 ;
                if(j1 == j2) value = grid[i][j1] ;
                else value = grid[i][j1] + grid[i][j2] ;

                value += solve(i+1 , j1 + dj1 , j2 + dj2 , grid) ;

                maxi = max(maxi , value) ;
            }
        }

        return dp[i][j1][j2] = maxi ;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        R = grid.size() ;
        C = grid[0].size() ;

        dp.resize(R , vector<vector<int>>(C , vector<int>(C , -1))) ;

        return solve(0 , 0 , C-1 , grid) ;
    }
};

// space optimization
class Solution1 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size() ;
        int C = grid[0].size() ;

        vector<vector<int>> front(C , vector<int>(C , 0)) ;
        vector<vector<int>> curr(C , vector<int>(C , 0)) ;

        // base case
        for(int j1 = 0 ; j1 < C ; j1++){
            for(int j2 = 0 ; j2 < C ; j2++){
                if(j1 == j2) front[j1][j2] = grid[R-1][j1] ;
                else front[j1][j2] = grid[R-1][j1] + grid[R-1][j2] ;
            }
        }

        for(int i = R-2 ; i >= 0 ; i--){
            for(int j1 = 0 ; j1 < C ; j1++){
                for(int j2 = 0 ; j2 < C ; j2++){
                    int maxi = -1e8 ;
                    // explore all paths
                    for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
                        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                            int value = 0 ;
                            if(j1 == j2) value = grid[i][j1] ;
                            else value = grid[i][j1] + grid[i][j2] ;

                            if(j1 + dj1 >= 0 && j1 + dj1 < C && j2 + dj2 >= 0 && j2 + dj2 < C)
                                value += front[j1 + dj1][j2 + dj2] ;
                            else
                                value += -1e8 ;

                            maxi = max(maxi , value) ;
                        }
                    }
                    curr[j1][j2] = maxi ;
                }
            }
            front = curr ;
        }

        return front[0][C-1] ;
    }
};

int main() {
    Solution1 sol;
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}
    };
    cout << "Maximum cherries collected: " << sol.cherryPickup(grid) << endl;
    return 0;
}