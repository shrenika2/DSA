#include<iostream>
#include<vector>
#include<climits>
using namespace std;    

class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i; // each node is its own parent
        }
    }

    int findparent(int node) {
        if (node == parent[node]) {
            return node; // root found
        }
        return parent[node] = findparent(parent[node]); // path compression
    }

    bool find(int u, int v) {
        return findparent(u) == findparent(v);
    }

    void unionByRank(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } 
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int main() {
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.find(3, 7)) {
        cout << "Same Parent" << endl;
    } else {
        cout << "Different Parent" << endl;
    }

    ds.unionBySize(3, 7);

    if (ds.find(3, 7)) {
        cout << "Same Parent" << endl;
    } else {
        cout << "Different Parent" << endl;
    }

    return 0;
}