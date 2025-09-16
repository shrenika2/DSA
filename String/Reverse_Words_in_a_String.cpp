#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std ;


// tc = o(n)
// sc = o(n)
class Solution {
public:
    string reverseWords(string s) {
        vector <string> words;
        string word = "";
        for (auto it : s){
            if (it != ' '){
                word += it;
            }else{
                if (!word.empty()){
                    words.push_back(word);
                    word = "";
                }
            }
        }
            if (!word.empty()){
                    words.push_back(word);
                }

                reverse(words.begin() , words.end());

                string result = "";
                for (int i=0 ; i < words.size() ; i++){
                    result += words[i];
                    if (i != words.size()-1) result += " ";
                }
        
        return result;

        
    }
};