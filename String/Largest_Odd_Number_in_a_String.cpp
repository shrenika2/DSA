#include <iostream>
#include <string>

using namespace std ;
 
// tc = o(n)
// sc = o(n)
class Solution{	
public:		
    string largeOddNum(string& s){
        int n = s.size();
        int lastele = -1;
        for (int i=n-1 ; i >=0; i--){
            if ((s[i]-'0') % 2 == 1){
                lastele = i;
                break;
            }
        }
        if (lastele == -1) return "";

        string result = s.substr(0 , lastele + 1 );

        int start = 0 ;
        if (start <result.size() && result[start]=='0' ){
            start++;
        }      
        result = result.substr(start);
        
        return result.empty() ? "0":result;  //your code goes here
    }
};