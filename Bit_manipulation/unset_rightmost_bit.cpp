#include <iostream>
#include <vector>

using namespace std ;

class Solution{
    int Unset_rightmost_bit(int n){
        return n & (n-1);
    }
    
};