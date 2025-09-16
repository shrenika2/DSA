#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>

using namespace std ;
// optimal 
// tc =   O(n × log(maxNum))
// sc =  o(1)

class Solution {
public:

    int canDivide(vector<int>& nums , int divisor){
        int total = 0 ;
        for (int num : nums ){
            total += ceil(num/(double)divisor);
        }
        return total ;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 ;
        int mx= *max_element(nums.begin() , nums.end());
        int answer = -1 ;

        while (low <= mx ){
            int mid = low + (mx - low)/2;
            if (canDivide(nums , mid) <= threshold ){
            answer = mid ;
            mx = mid -1 ;

        }else {
            low = mid + 1;

        }
        }
        return answer;

        
    }
};