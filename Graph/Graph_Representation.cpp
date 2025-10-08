#include<iostream>
#include<vector>
using namespace std ;
// adjacent list
int main(){
    int n , m ;
    cin >> n >> m ;
    vector <int> adj[n];
    for (int i=0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;  
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    for (int i=0 ; i < n ; i++){
        cout << i << " ";
        for (int v : adj[i])
        cout << v << " ";
        cout << endl;
    }
}