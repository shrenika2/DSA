#include <iostream>
#include < vector>

using namespace std ;

// tc = o(1)
// sc = o(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal ;
        int ans = 0 ;
        while (x){
            ans += (x&1);
            x=x>>1;

        }
        return ans ;
        
    }
};