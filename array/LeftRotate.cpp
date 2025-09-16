#include <iostream>
#include <vector>
#include<set>

using namespace std ;

int leftRotate(int n , vector<int>a){
    int temp=a[0];
    for (int i=1 ; i < n ; i++){
        a[i-1]=a[i];
    }
    a[n-1]=temp;
    for (int i=0 ; i < n ; i++){
        return a[i];
    }
    
}

int main (){
    int n ;
    cin >> n ;
    vector<int>a;
    for (int i=0 ; i < n ; i++){
        cin >> a[i];
    }
    leftRotate(n , a);
    
}
