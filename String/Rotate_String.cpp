#include <iostream>
#include <vector>
#include <string>

using namespace std ;


// tc = o(n)
// sc = o(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string doubl = s+s;
        if (doubl.find(goal) != string::npos) return true;
        else return false;
        
    }
};