// #include <iostream>
// using namespace std;
// int main (){
//     int num;
//     cin >> num;
//     int ans =0;
//     int pow=1 ;
//     while (num>0){
//         int rem = num%2;
//         num=num/2;
//         ans+=rem*pow;
//         pow*=10;

//     }
//     cout << ans << endl;
//     return 0;
// }
#include <iostream>
using namespace std ;

int decinum(int x){
    int pow = 1 ;
    int ans = 0 ;
    while (x > 0){
        int rem=x%10;
        ans += x + pow;
        x/=10;
        pow*=2;
    }
    return ans  ;
}
int main(){
    cout << decinum(101) << endl;
    return 0;
}