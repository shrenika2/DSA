#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

// tc = o(n) + o(2e) && sc = o(3n)
void bfs(int v , vector<int> adj[]){
    vector<int> visited(v , 0);
    queue<int> q ;

    visited[0]=1;
    q.push(0);

    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]){
            if (!visited[neighbor]){
                visited[neighbor]= 1;
                q.push(neighbor);
            }
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

    bfs(V, adj);
    return 0;
}