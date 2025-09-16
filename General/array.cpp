#include <iostream>
#include <algorithm>
#include<vector>
#include<cmath>
using namespace std ;
int main (){
    int a[4]={13,34,-45,36};
    int mx=INT_MIN;
    int we=0;
    for (int i=0 ; i < 4 ; i++){
        mx=max({a[i], mx});
        we=i;

    }
    cout << we<< endl;

}

