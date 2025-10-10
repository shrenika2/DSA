#include <iostream>
#include<queue>

using namespace std ;

class Solution {
public:
    int orangeRotting(vector<vector<int>> & grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>> q;
        int fresh = 0 ;

        for (int i=0 ; i < n ; i++){
            for (int j=0 ; j < m ; j++){
                if (grid[i][j] == 2){
                    q.push({i , j});
                }else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int drow[] = {-1 , 1 , 0 , 0};
        int dcol[] = {0 , 0 , -1 , 1};

        int time = 0 ;

        while (!q.empty() && fresh > 0){
            int size = q.size();

            for (int i=0 ; i < size ; i++){
                auto [r , c] = q.front();
                q.pop();

                for (int k=0 ; k < 4 ; k++){
                    int nr = r + drow[k];
                    int nc = c + dcol[k];

                    if (nr>=0 && nr<n && nc >= 0 && nc < m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr , nc});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return (fresh==0)? time : -1;
    }
};

int main (){
    Solution S ;
    vector<vector<int>> grid = {
        {2 , 1 , 1}, 
        {1 , 1 , 0},
        {0 , 1 , 1}
    };
    cout << S.orangeRotting(grid) << endl;
    return 0;
}
