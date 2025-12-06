#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include "Disjoint_Set.cpp"
using namespace std;

class Solution{
    public :

    int spanning_Tree(int v , vector<vector<int>> adj[]){
        vector<vector<int>> edges;

        for (int u=0 ; u < v ; u++){
            for (auto it : adj[edges]){
                int v = it[0];
                int wt = it[1];
                if (u < v){
                    edges.push_back({wt , u , v});
                }
            }
        }

        sort(edges.begin() , edges.end());

        DisjointSet ds(v);
        int mst_weight = 0;

        for (auto e : edges){
            int wt = e[0];
            int u = e[1];
            int v = e[2];

            if (ds.findparent(u) != ds.findparent(v)){
                ds.unionByRank(u , v);
                mst_weight += wt;
            }
        }
    }
};
int main(){
    int V = 5;
    vector<vector<int>> adj[V];

    adj[0].push_back({1 , 2});
    adj[0].push_back({3 , 6});
    adj[1].push_back({0 , 2});
    adj[1].push_back({2 , 3});
    adj[1].push_back({3 , 8});
    adj[1].push_back({4 , 5});
    adj[2].push_back({1 , 3});
    adj[2].push_back({4 , 7});
    adj[3].push_back({0 , 6});
    adj[3].push_back({1 , 8});
    adj[4].push_back({1 , 5});
    adj[4].push_back({2 , 7});

    Solution obj;
    int mst_weight = obj.spanning_Tree(V , adj);
    cout << "Weight of Minimum Spanning Tree is: " << mst_weight << endl;

    return 0;
}