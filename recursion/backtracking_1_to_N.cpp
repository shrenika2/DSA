#include <iostream>
using namespace std ;

void backtrack(int i , int n){
    if (i<n) return;
    backtrack(i-1 , n);
    cout << i << endl;
}
int main (){
    int i , n ;
    cin >> i >> n ;
    backtrack(i , n);
    return 0;
}