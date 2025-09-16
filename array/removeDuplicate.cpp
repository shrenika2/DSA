// BruteForce

// #include <iostream>
// #include <vector>
// #include<set>

// using namespace std ;

// int removeDuplicate(int n , vector<int>a){
//     set<int>st;
//     for (int i=0 ; i < n ; i++){
//         st.insert(a[i]);
//     }
//     int index = 0;
//     for (auto it:st){
//         a[index]=it;
//         index++;
//     }
//     return index;
// }

// int main (){
//     int n ;
//     cin >> n ;
//     vector<int>a;
//     for (int i=0 ; i < n ; i++){
//         cin >> a[i];
//     }

//     removeDuplicate(n , a);
// }

// optimal


#include <iostream>
#include <vector>
#include<set>

using namespace std ;

int removeDuplicate(int n , vector<int>a){
    int i=0 ; 
    for (int j=1 ; j < n ; j++){
        if (a[i]!=a[j]){
        a[i+1]=a[j];
        i++;
        }
    }
    return i+1;
    
}

int main (){
    int n ;
    cin >> n ;
    vector<int>a;
    for (int i=0 ; i < n ; i++){
        cin >> a[i];
    }
    removeDuplicate(n , a);
    
}
