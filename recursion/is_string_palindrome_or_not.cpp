#include <iostream>
using namespace std ;

bool is_string_pali(int i , string s){
    if(i>=s.size()/2) return true ;
    if (s[i]!=s[s.size()-i-1]) return false;
    return is_string_pali(i+1 , s);
}

int main (){
    string s ;
    cin >> s ;
    cout << is_string_pali(0 , s);
    return 0;
}