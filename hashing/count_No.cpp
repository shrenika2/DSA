#include <iostream>
#include <vector>
using namespace std ;

int count(int n , int a[]){
    int cnt=0;
    for (int i=0; i<sizeof a ; i++){
        if (a[i]==n) cnt+=1;
    }
    return cnt;
}

int main (){
    int n ;
    cin >> n ;
    vector <int> a();
    for (int i=0 ; i< sizeof a ; i++){
        cin >> a[i];
    }return 0;
}