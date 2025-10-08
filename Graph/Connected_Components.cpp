#include<iostream>
#include<vector>
using namespace std ;

void dfs(int node , vector<int> adj[] , vector<int> &visited){
    visited[node]=1;
    for (int it : adj[node]){
        if (!visited[it]){
            dfs(it , adj , visited);
        }
    }
}

int main (){
    int v , e ;
    cin >> v >> e;
    
    vector<int> adj[v];
    for (int i=0 ; i < e ; i++){
        int u , v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(v , 0);
    int comp = 0 ;

    for (int i=0 ; i < v ; i++){
        if (!visited[i]){
            comp++;
            dfs(i , adj , visited);
        }
    }
    cout << comp << endl;
}