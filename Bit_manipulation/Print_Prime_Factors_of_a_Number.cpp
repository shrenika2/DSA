#include <iostream>
#include  <vector>

using namespace std ;

// Time Complexity	O(n × √maxVal)
//Space Complexity	O(S) where S = total number of prime factors
class Solution{
    public:
        vector<vector<int>> primeFactors(vector<int>& queries){
            //your code goes here
            vector<vector<int>> result ;

            for (int num : queries){
                vector<int>factors;

                while (num%2==0){
                    factors.push_back(2);
                    num/=2;
                }

                for (int i=3 ; i*i <= num ; i+=2){
                    while (num%i == 0){
                        factors.push_back(i);
                        num/=i;
                    }
                }
                if (num > 1){
                    factors.push_back(num);
                }
                result.push_back(factors);
            }
            return result;
        }
};
