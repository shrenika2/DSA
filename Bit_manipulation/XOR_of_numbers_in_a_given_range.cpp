#include <iostream>
#include <vector>

// tc = o(1)
// sc = o(1)
class Solution{	
	public:

        int function(int n){
            if (n%4==0) return n ;
            else if (n%4==1) return 1 ;
            else if (n%4==2) return n+1;
            else return 0;
            
        }
		int findRangeXOR(int l,int r){
			return function(r) ^ function(l-1);
		}
};