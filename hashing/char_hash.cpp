// #include <iostream>
// #include<string>
// using namespace std ;

// int main (){
//     string s ;
//     cin >> s;

//     // precompute 
//     int hash[256]={0}; // 256 characters   
//     for (int i=0 ; i < s.size();i++){
//         hash[s[i]]++;
//     }

//     int q ;
//     cin >> q ;
//     while (q--){
//         char c ;
//         cin >> c ;
//         //fetch
//         cout << hash[c] << endl;
//     }
//     return 0;
// }

// if I knew all  inputs are lowercase 
#include <iostream>
#include<string>
using namespace std ;

int main (){
    string s ;
    cin >> s;

    // precompute 
    int hash[26]={0};// if 256 then no need to minus 'a' 
    for (int i=0 ; i < s.size();i++){
        hash[s[i]-'a']++;
    }

    int q ;
    cin >> q ;
    while (q--){
        char c ;
        cin >> c ;
        //fetch
        cout << hash[c-'a'] << endl;
    }
    return 0;
}