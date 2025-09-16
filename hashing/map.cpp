// #include <iostream>
// #include<vector>
// #include<map>
// #include<cmath>
// #include<climits>
// using namespace std ;

// int main (){
//     int mx=0;
//     int mn=INT_MAX;
//     int n ;
//     cin >> n ;
//     int arr[n];
//     for (int i=0 ; i < n ; i++){
//         cin >> arr[i];
//         }

//         map<int , int >mpp;
//         for (int i=0 ; i < n ; i++){
//             mpp[arr[i]]++;
//         }
//         vector <int , int > mxe , mne;
//         for (auto it:mpp){
//             cout << it.first << "-->" << it.second << endl;
        
//         mx = max(mx , it.second);
//         mn = min(mn,it.second);
//         }

//     int q ;
//     cin >> q ;
//     while (q--){
//         int num;
//         cin>> num;
//         cout << mpp[num] << endl;
//     }
//         cout << "Minimum :" << mn << endl;
//         cout << "Maximum :" << mx << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <map>
#include <climits> // for INT_MAX
using namespace std;

int main() {
    int mx = 0;
    int mn = INT_MAX;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> mpp;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    // Variables to store elements with max and min freq
    vector<int> maxFreqElements, minFreqElements;

    for (auto it : mpp) {
        cout << it.first << " --> " << it.second << endl;

        if (it.second > mx) {
            mx = it.second;
            maxFreqElements.clear(); // reset the list
            maxFreqElements.push_back(it.first);
        } else if (it.second == mx) {
            maxFreqElements.push_back(it.first);
        }

        if (it.second < mn) {
            mn = it.second;
            minFreqElements.clear(); // reset the list
            minFreqElements.push_back(it.first);
        } else if (it.second == mn) {
            minFreqElements.push_back(it.first);
        }
    }

    // Query section
    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        cout << "Frequency of " << num << " is " << mpp[num] << endl;
    }

    // Print min and max frequencies and their elements
    cout << "Minimum Frequency: " << mn << " -> ";
    for (int val : minFreqElements)
        cout << val << " ";
    cout << endl;

    cout << "Maximum Frequency: " << mx << " -> ";
    for (int val : maxFreqElements)
        cout << val << " ";
    cout << endl;

    return 0;
}
