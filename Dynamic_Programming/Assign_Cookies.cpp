#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    int contentChildren = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            contentChildren++;
            i++;
            j++;
        }
        j++;
    }
    return contentChildren;
}

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << "Number of content children: " << findContentChildren(g, s) << endl;
    return 0;
}