#include<iostream>
#include<vector>
#include<climits>
using namespace std;    

class Solution {
public:

    class Disjointset {
    public:
        vector<int> parent, size;

        Disjointset(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findparent(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findparent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int pu = findparent(u);
            int pv = findparent(v);

            if (pu == pv) return;

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        Disjointset ds(n);

        for (auto &c : connections) {
            int u = c[0];
            int v = c[1];
            ds.unionBySize(u, v);
        }

        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findparent(i) == i)
                comp++;
        }

        return comp - 1;
    }
};

int main(){
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    cout << sol.makeConnected(n, connections) << endl; // Output: 1
    return 0;
}