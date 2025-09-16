#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    void moveZeroes_Brute(vector<int>& a) {
        vector<int> temp;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 0) {
                temp.push_back(a[i]);
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            a[i] = temp[i];
        }
        for (int i = temp.size(); i < a.size(); i++) {
            a[i] = 0;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& a) {
        int j = -1;
        int n = a.size();

        // Find index of first zero
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zero is found, array is already fine
        if (j == -1) return;

        // Move non-zero elements forward and place zeros at the end
        for (int i = j + 1; i < n; i++) {
            if (a[i] != 0) {
                swap(a[i], a[j]);
                j++;
            }
        }
    }
};


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solution1 s1;
    s1.moveZeroes_Brute(a);

    cout << "Output: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

