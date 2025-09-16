#include <iostream>
#include <vector>
using namespace std;

// Brute force approach
vector<int> solve_brute(vector<int>& a, int n, vector<int>& b, int m) {
    vector<int> ans;
    int vis[1000] = {0};  // Assuming m <= 1000 for this example

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j] && vis[j] == 0) {
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
        }
    }
    return ans;
}

// Optimal approach (two pointers) - arrays must be sorted
vector<int> solve_optimal(vector<int>& a, int n, vector<int>& b, int m) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 3, 5};
    int n = a.size();
    int m = b.size();

    // Use brute or optimal as needed
    vector<int> result = solve_optimal(a, n, b, m);
    // vector<int> result = solve_brute(a, n, b, m);

    cout << "Intersection: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}
