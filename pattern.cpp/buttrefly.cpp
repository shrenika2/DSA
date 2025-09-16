#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n ;
    for (int i=0 ; i < n ; i++){
        for (int j=0 ; j < i; j++){
            cout << "*" ;
        }
        if (i!=n-1){
        for (int j=2*i ; j>0  ; j++){
            cout << " " ;
        }
        }
        for (int j=0 ; j < i; j++){
            cout << "*";
        }
        cout << endl;
    }
    for (int i=0 ; i < n ; i++){
        for (int j=n-i ; j> 0 ; j--){
            cout << "*";
        }
        if (i!=0){
        for (int j=0 ; j <2*i ; j++){
            cout << " " ;
        }
        }
        for (int j=n-i ; j> 0 ; j--){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
    
}