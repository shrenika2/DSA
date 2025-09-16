#include <iostream>
#include <vector>
using namespace std ;

int nCr(int row , int column){
    long long res= row ;
    for (int i=0 ; i < column ; i++){
        res*=(row-i);
        res/=(i+1);
    }
    return res;
}

vector <long long> given_row(int row){
    vector <long long > num;
    int val = 1 ;
    for (int col = 0 ; col <=row ; col++){
        num.push_back(val);
        val*=val * (row - col)/(col+1);

    }
    return num;
}

class Solution {

    vector<int> generate_row(int row){
        vector<int> rowa;           // Store each row
        long long val = 1;          // Use long long to prevent overflow

        for (int col = 0; col <= row; col++) {
            rowa.push_back(static_cast<int>(val));  // Add value to row
            val = val * (row - col) / (col + 1);     // Update val for next column
        }

        return rowa;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            ans.push_back(generate_row(i));  // Correct function call
        }

        return ans;
    }
};
