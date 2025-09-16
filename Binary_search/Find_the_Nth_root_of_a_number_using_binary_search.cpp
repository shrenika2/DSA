#include <iostream>
#include <vector>
using namespace std ;


// better 
// tc = O(log(x / ε))
// sc = o(1)
class Solution {
public:
    long long nthroot(long long n , int x)  {
        double low = 1 ;
        double high = x ;
        double eps = 1e-6;//0.000001
        while ((high-low) > eps){
            double mid = low + (high-low)/2 ;
            if ((long long)pow(mid , n) < x){
                low = mid;
            }else{
                high = mid;
            }
        }
        return low;
    }
};