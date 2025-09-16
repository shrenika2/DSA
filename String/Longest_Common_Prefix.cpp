#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& v) {
        int n = v.size();
        if (n == 0) return "";
        string result = "";
        sort(v.begin() , v.end());
        string first = v[0], last = v[n-1];
        
        for (int i=0 ; i < min(first.size() , last.size()) ; i++){
            if (first[i] != last[i]){
                return result;
            }
            result+=first[i];
        }
        return result;
    }

};