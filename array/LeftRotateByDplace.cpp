#include <iostream>
#include <vector>
#include<set>
#include<algorithm>

using namespace std ;

int LeftRotateByDplace_bruteforce(int n , vector<int>a , int d){
    d%=n;
    vector<int>temp;
    for(int i=0 ; i < d ; i++){
        temp[i]=a[i];
    }
    for (int i=d ; i < n ; i++){
    a[i-d]=a[i];
}
    for (int i=n-d ; i < n ; i++){
        a[i]=temp[i-(n-d)];
    }
}

int LeftRotateByDplace_optimal(int n , vector<int>a , int d){
   d %= n;
    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
}

int main (){
    int n ;
    cin >> n ;
    vector<int>a;
    for (int i=0 ; i < n ; i++){
        cin >> a[i];
    }
    int d ;
    cin >> d;
    LeftRotateByDplace_bruteforce(n , a , d);
    for (int i=0 ; i < n ;i++){
        cout << a[i];
    }
    
}
