#include <iostream>
#include <vector>
#include <map>
using namespace std ;

// brute 
// tc = o(n^3)
// sc = o(1)

class Solution{
public:

    int subarray(vector <int> a , int target){
        int n = a.size();
        int cnt = 0;
        for (int i=0 ; i < n ; i++){
            for (int j=i ; j < n ; j++){
                int xor_sum=0;
                for (int k=i ; k < j ; k++){
                    xor_sum^=a[k];   
                }
                if (xor_sum==target){
                    cnt++;
                }
            }
        }
        return cnt ;
    }
};

// better
// tc = o(n^3)
// sc = o(n^3)

class Solution{
public:

    vector <vector<int>> subarray(vector <int> a , int target){
        int n = a.size();
        vector <vector <int>> result;
        for (int i=0 ; i < n ; i++){
            int xor_sum=0;
            for (int j=i ; j < n ; j++){
                xor_sum^=a[j];
                if (xor_sum==target){
                    vector <int > subarray_temp(a.begin()+i , a.end()+j+1 );//This line creates a new vector named subarray that contains a slice (or subarray) from the original vector a.
                    result.push_back(subarray_temp);


                }
            }
        }
        return result ;
    }
};


//optimal 
// tc = o(n)
// sc = o(n)
class Solution {
public:
    int subarray(vector<int> a, int target) {
        int n = a.size();
        int xr = 0;
        map<int, int> mpp;
        mpp[0] = 1; // Instead of mpp[xr]++, do mpp[0] = 1 for clarity
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            xr = xr ^ a[i];  // prefix XOR up to index i
            int x = xr ^ target;  // what we need as previous prefix XOR
            cnt += mpp[x];        // how many times that XOR occurred
            mpp[xr]++;            // record current prefix XOR
        }
        return cnt;
    }
};
