#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        priority_queue<
            pair<int , int>,
            vector<pair<int , int>>, 
            greater<pair<int , int>>
        >pq;

        vector<bool> visited(V , false);
        pq.push({0 , 0});
        int mstwt = 0;

        while (!pq.empty()){
            auto[wt , node] = pq.top();
            pq.pop();

            if (visited[node]) continue;

            visited[node]=true;
            mstwt+=wt;

            for (auto edge : adj[node]){
                int adjnode = edge[0];
                int wtt = edge[1];
                if (!visited[adjnode]){
                pq.push({wtt , adjnode});
           }
            }


        }
        return mstwt;
       
    }
};

int main(){
    Solution sol;
    int V ;
    cin >> V ;
    vector<vector<int>> adj[V] ;
    int E ;
    cin >> E ;
    for(int i = 0 ; i < E ; i++){
        int u , v , w ;
        cin >> u >> v >> w ;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }
    cout << sol.spanningTree(V , adj) << endl;
    return 0;
}