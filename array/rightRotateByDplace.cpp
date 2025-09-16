#include <iostream>
#include <vector>
#include<set>
#include<algorithm>

using namespace std ;

int RightRotateByDplace_bruteforce(int n , vector<int>a , int d){
    d%=n;
    vector<int>temp;
    for(int i=n-d ; i < n ; i++){
        temp[i]=a[i];
    }
    for (int i=n-d-1 ; i >=0 ; i--){
    a[i+d]=a[i];
}
    int z=0;
    for (int i=0 ; i < d ; i++){
        a[i]=temp[z];
        z++;
    }
}

int RightRotateByDplace_optimal(int n , vector<int>a , int d){
   d %= n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin()+d);
    reverse(a.begin()+d, a.end());
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
    RightRotateByDplace_bruteforce(n , a , d);
    for (int i=0 ; i < n ;i++){
        cout << a[i];
    }
    
}
