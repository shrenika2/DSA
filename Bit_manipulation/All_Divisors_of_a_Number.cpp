#include <iostream>
#include <vector>

using namespace std ;
//tc = Time: O(√n) for loop + O(k) to reverse/merge = O(√n)
//Space: O(k) where k is the number of divisors.
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> smallDivs, largeDivs;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                smallDivs.push_back(i);
                if (i != n / i) {
                    largeDivs.push_back(n / i);  // Store separately for later reverse
                }
            }
        }

        // Combine: smallDivs is in ascending order, reverse largeDivs to continue ascending
        reverse(largeDivs.begin(), largeDivs.end());
        smallDivs.insert(smallDivs.end(), largeDivs.begin(), largeDivs.end());

        return smallDivs;
    }
};
