#include <iostream>
#include <vector>

using namespace std ;


class Solution {
public:
    int countSetBits(int n) {
        // Your code goes here
        return __builtin_popcount(n);
    }
};