#include <iostream>
using namespace std ;

int summ(int n ){
    if (n==0) return 0;
    return n+summ(n-1);
}

int main (){
    int n ;
    cin >> n ;
    cout << summ(n);
    return 0;
}

