#include <iostream>
#include <vector>
using namespace std;

int largest_element(vector<int>& arr, int n) {
    int le = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > le) {
            le = arr[i];
        }
    }
    return le;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxElement = largest_element(arr, n);
    cout << "Largest element: " << maxElement << endl;

    return 0;
}
