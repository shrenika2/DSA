#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std ;

// brute force   
// tc = o(n^2)
// sc = o(n) == result array
vector<int> maj_ele(vector<int> & a){
    int n = a.size();
    vector <int> res;
    for (int i=0 ; i < n ; i++){
        int count = 0 ;
        for (int j=0 ; j < n ; j++){
            if (a[i]==a[j]){
                count ++;
            }
        }
       if( find(res.begin(), res.end(), a[i]) == res.end()){
            res.push_back(a[i]);
        }
    }
    return res ;
    
    
} 

// better 
// tc = o(n)
/// sc = o(n)
vector <int>  maj_ele_better(vector <int > & b ){
    int n = b.size();
    unordered_map <int , int > freq;
    vector <int > ress;

    for (int i = 0 ; i < n ; i++) {
        freq[b[i]]++;
    }
    for (auto it : freq){
        if (it.second>(n/3)){
            ress.push_back(it.first);
        }
    }
    return ress;
}

// optimal
// tc = o(n)
// sc = o(1)
// Boyer-Moore Voting Algorithm (Extended Version)

vector <int >  maj_ele_optimal(vector <int > &num){
    int n = num.size();
    
    int cnt1=0 , cnt2=0;
    int ele1=INT_MIN , ele2=INT_MIN;// we want initialize with those elements which are not present in this array
    for (int i=0 ; i < n ; i++){
        if (cnt1=0 && num[i]!=ele2){
            cnt1++;
            ele1=num[i];
        }else if (cnt2=0 && num[i]!=ele1){
            cnt2++;
            ele2=num[i];
        }else if (num[i]==ele1) {
            cnt1++;
        }else if (num[i]==ele2){
            cnt2++;
        }else {
            cnt1--;
            cnt2--;
        }
    }
    vector <int >ls;
    cnt1=0 , cnt2=0;
    for (int i=0 ; i < n ; i++){
        if (ele1==num[i]) cnt1++;
        if (ele2==num[i]) cnt2++;
    }
    int mini = (int) (n/3)+1;
    if (cnt1 >=mini) ls.push_back(ele1);
    if (cnt2 >= mini) ls.push_back(ele2);
    sort (ls.begin() , ls.end());
    return ls;
}

int main (){
    
}