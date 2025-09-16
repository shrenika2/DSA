#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// tc = o(n)
// sc = o(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {0} ;

        for (auto it : s){
            freq[it - 'a']++;
        }
        for (auto it : t){
            freq[it - 'a']--;
        }
        for (auto count : freq){
            if (count != 0){
                return false;
            }
        }
        return true;
    }
    
};

// tc = o(n log n)
// sc =  o(1) or o(n)  depends on the sorting  
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort (s.begin() , s.end());
        sort (t.begin() , t.end());
        return s == t;
    }
    
};