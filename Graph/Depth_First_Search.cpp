#include <iostream>
#include <vector>
using namespace std ;

void dfs(int node , vector<int> adj[] , vector<int> & visited){
    visited[node]=1;
    cout << node << " ";

    for (int neighbor : adj[node]){
        if (!visited[neighbor]){
            dfs(neighbor , adj , visited);
        }
    }
}

int main() {
    int V = 5;
    vector<int> adj[V];

    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1};
    adj[3] = {0};
    adj[4] = {1};

    vector<int> visited(V, 0);
    dfs(0, adj, visited);

    return 0;
}