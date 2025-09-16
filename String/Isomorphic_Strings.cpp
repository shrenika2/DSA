#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std ;

// tc = o(n)
// sc = o(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST; // s -> t
        unordered_map<char, char> mapTS; // t -> s

        for (int i = 0; i < s.length(); ++i) {
            char fromS = s[i];
            char fromT = t[i];

            // Check s → t mapping
            if (mapST.count(fromS)) {
                if (mapST[fromS] != fromT) return false;
            } else {
                mapST[fromS] = fromT;
            }

            // Check t → s mapping (reverse)
            if (mapTS.count(fromT)) {
                if (mapTS[fromT] != fromS) return false;
            } else {
                mapTS[fromT] = fromS;
            }
        }

        return true;
    }
};

// tc = o(n)
// sc = o(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return -1;
        char s_t[256]={0};
        char t_s[256]={0};

        for (int i=0 ; i < s.size() ; i++){
            char sc = s[i];
            char tc = t[i];

            if (s_t[sc] && s_t[sc] != tc) return false;
            if (t_s[tc] && t_s[tc] != sc) return false;

            s_t[sc]=tc;
            t_s[tc]=sc; 
        }
        return true ;
        
    }
};