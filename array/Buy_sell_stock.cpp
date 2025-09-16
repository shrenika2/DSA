#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int mxprofit=0;
        for (int i=0 ; i < n ; i++){
            int cost = prices[i]-mn;
            mn=min(mn , prices[i]);
            mxprofit=max(mxprofit , cost);
        }
        if (mxprofit!=0){
            return mxprofit;
        }else {
            return 0;
        }
        
    }
};//tc=o(n)  && s(c)= o(1)