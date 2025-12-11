#include<iostream>
#include<vector>
using namespace std;

//memoization

class Solution {
public:
    int ninjaTraining(int n, vector<vector<int>>& points) {

        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){

                dp[day][last] = 0;
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        dp[day][last] = max(dp[day][last],
                                points[day][task] + dp[day-1][task]);
                    }
                }
            }
        }

        return dp[n-1][3];
    }
};

//space optimization
class Solution1 {
public:
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> prev(4 , 0);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1 ; day < n ; day++){
            vector<int>curr(4 , 0);
            for (int last = 0 ; last<4 ; last++){
                curr[last]=0;

                for (int task = 0 ; task< 3 ; task++){
                    if (task!=last){
                        curr[last] = max(curr[last] , points[day][task]+prev[task]);
                    }
                }
            }
            prev = curr;
        }
        return prev[3];

    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>> points(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>points[i][j];
        }
    }
    Solution sol;
    cout<<sol.ninjaTraining(n, points)<<endl;
    return 0;
}
