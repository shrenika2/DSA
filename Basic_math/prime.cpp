// #include<iostream>
// using namespace std;
// int main (){
//     int n=5 ;
//     bool isprime=true;
//     for (int i=2 ; i <=n-1 ; i++){
//         if (n%i==0){
//             isprime = false ;
//             break;
//         }
//     }
//      if(isprime == true){
//         cout << "prime" << endl;

//     }else {
//         cout << "non prime" << endl;
//     }
//     return 0 ;

// }

#include <iostream>
using namespace std ;

bool ispri(int n){
    if (n<=1) return false;
    if (n<=3) return true ;
    if (n%2==0 || n%3==0) return false;
    for (int i=5 ; i * i <= n ; i++){
        if (n%i==0 || n%(i+2)==0) return false;
    }
    return true ;
}

int main (){
    int n ;
    cin >> n ;
    cout << ispri(n)?"pri":"not pri";
    return 0;
}