#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Disjoint {
public:
    vector<int> parent, size;

    Disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionset(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        int maxNode = 20005;

        Disjoint ds(maxNode);
        unordered_set<int> un; 

        for (auto &s : stones) {
            int r = s[0];
            int c = s[1] + 10001;  
            ds.unionset(r, c);

            un.insert(r);
            un.insert(c);
        }

        int comp = 0;

        for (int node : un) {
            if (ds.findParent(node) == node)
                comp++;
        }

        return n - comp;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << sol.removeStones(stones) << endl; // Output: 5
    return 0;
}