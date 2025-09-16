#include <iostream>
#include <vector>

using namespace std ;


//Component	Time Complexity	Space Complexity
//Sieve Precomputation	O(N log log N)	O(N)
//Prime Factorization	O(Q * log M)	O(Q * log M)
//Total	O(N log log N + Q log M)	O(N + Q log M)
class Solution {
    const int MAXN = 1e6 + 1;
    vector<int> spf;

    void sieve() {
        spf.resize(MAXN);
        for (int i = 1; i < MAXN; i++) spf[i] = i;

        for (int i = 2; i * i < MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXN; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    vector<int> getFactors(int n) {
        vector<int> res;
        while (n > 1) {
            res.push_back(spf[n]);
            n /= spf[n];
        }
        return res;
    }

public:
    vector<vector<int>> primeFactors(vector<int>& queries) {
        sieve();  // Precompute smallest prime factors

        vector<vector<int>> result;

        for (int q : queries) {
            result.push_back(getFactors(q));
        }

        return result;
    }
};
