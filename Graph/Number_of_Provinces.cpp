#include<iostream>
#include <vector>

using namespace std ;

class Solution {
private:
    void dfs(int node , vector<int> adjLs[] , int vis[]){
        vis[node]=1;
        for (auto it : adjLs[node]){
            if (!vis[it]){
                dfs(it , adjLs , vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj , int v){
        vector<int> adjLs[v];
        for (int i=0 ; i < v ; i++){
            for(int j=0 ;j < v ; j++){
                if (adj[i][j] ==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[v]={0};
        int cnt = 0 ;

        for (int i=0 ; i < v ; i++){
            if (!vis[i]){
                cnt++;
                dfs(i , adjLs , vis);
            }
        }
        return cnt ;
    }
};

int main (){
    Solution s ;
    vector <vector<int>> isConnected = {
        {1 , 1 , 0},
        {1 , 1 , 0},
        {0 , 0 , 1}
    };

    int n = isConnected.size();
    cout << s.numProvinces(isConnected , n);
    return 0;
}

