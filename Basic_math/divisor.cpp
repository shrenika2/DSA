// #include <iostream>
// using namespace std ;

// void divisor(int n ){
//         for (int i=1 ; i <= n/2 ; i++){
//             if (n%i==0) cout << i << " ";
            
//         }
//         cout << n << " " ;
    
// }

// int main (){
//     int n ;
//     cin >> n ;
//      divisor(n);
// }

#include <iostream>
#include<set>
#include<cmath>
using namespace std ;

void divisor(int n){
    set<int>div;
    for (int i=1 ; i <= sqrt(n) ; i++){
        div.insert(i);
        div.insert(n/i);
    }

    for (int d : div){
        cout << d << endl;
    }
}

int main (){
    int n ;
    cin >> n ;
    divisor(n);
    return 0;
}