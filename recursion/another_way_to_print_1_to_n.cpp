// incresingly

#include <iostream>
using namespace std ;

int print (int i , int n){
    if (i>1) return ;
    print (i-1 , n);
    cout << i << endl;
    
}
int main (){
    int i , n ;
    cin >> i >> n;
    cout << print(n , n);
    return 0;
}


// decresingly

#include <iostream>
using namespace std ;

int print (int i , int n){
    if (i>n) return ;
    print (i+1 , n);
    cout << i << endl;
    
}
int main (){
    int i , n ;
    cin >> i >> n;
    cout << print(i , n);
    return 0;
}

