#include <iostream>
#include <vector>
#include <cmath>

using namespace std ;

int second_largest(vector<int>&a , int n){
    int lar=a[0];
    int sec_lar=INT_MIN;
    for (int i=1 ; i < n ; i++){
        if (a[i]>lar){
            sec_lar=lar;
            lar=a[i];
        }else if(a[i]<lar && a[i]>sec_lar){
            sec_lar=a[i];
        }
    }
    return sec_lar;
}

int second_smallest(vector<int> &a , int n){
    int small=a[0];
    int sec_small=INT_MAX;
    for (int i=1 ; i < n ; i++){
        if(a[i]<small){
            small=small;
            sec_small=a[i];
        }else if (a[i]!=small && a[i]<sec_small){
            sec_small=a[i];
        }
    }
    return sec_small;
}

int main (){
    int n ;
    cin >> n ;
    vector <int> &a();
    second_largest(a() , n);
    second_smallest(a() , n);
    return 0;

}