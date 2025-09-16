#include <iostream>
#include <vector>

using namespace std ;

bool printf(int ind , vector<int>&ds ,int s , int sum ,  int a[] , int n){
    if (ind==n){
        if (s==sum){
        for (auto it:ds)
            cout << it << " ";
        cout << endl;
        return true;
    }

    else return false;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    if(printf(ind+1 , ds , s ,sum , a , n)==true){
        return true;
    }
    s-=a[ind];
    ds.pop_back();

    if(printf(ind+1 , ds , s ,sum , a , n)==true){
        return true;
        return false;
    }
}

int main (){
    int a[]={3 , 1 , 2};
    int n=3;
    int sum = 2;
    
    vector <int > ds ;
    printf(0 , ds ,0 , sum , a , n);
    return 0;
}