#include <iostream>
#include <vector>
using namespace std ;


// brute force 
// tc = O(√n)
// sc = o(1)
class Solution {
public:
    long long floorSqrt(long long n)  {
        if (n==0 || n==1) return n ;
        int i = 1 ;
        while (i*i <= n){
            i++;
        }
        return i-1;
      
    }
};

// better 
// tc = o(log n)
// sc = o(1)
class Solution {
public:
    long long floorSqrt(long long n)  {
        int low = 1 ;
        int high = n ;
        while (low<=high){
            int mid = low + (high-low)/2 ;
            if ((long long)mid * mid <= n){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return high;
    }
};

// optimal 
// tc = o(1)
// sc = o(1)

class Solution {
public:
    long long floorSqrt(long long n)  {
        return floor(sqrt(n));
    }
};

