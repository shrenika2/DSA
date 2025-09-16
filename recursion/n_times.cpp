#include <iostream>
using namespace std ;

void print (int i , int n){
    if (i>n) return ;
    cout << "Shrenika" << endl;
    print (i+1 , n);
}
int main (){
    int i , n ;
    cin >> i >> n;
     print(i , n);
    return 0;
}

//TC O(n)
//SC O(n)
