// #include <iostream>
// using namespace std ;

// int main (){
//     int sum =0 ;
//     int n ;
//     cin >> n ;
//     int dub= n;
    
//     while (n>0){
//         int ld = n%10;
//         sum = sum + (ld * ld * ld);
//         n/=10;
//     }
//     if (dub==sum ) cout << "Yes" << endl;
//     else cout << "No" << endl;
// }

// #include <iostream>
// using namespace std ;

// bool isArmstrong(int n) {
//         if (n<0) return false ;
//         int am= 0 ;
//         while (n>0 || n==0){
//             int ld = n%10;
//             am = am + (ld*ld*ld);
//             n/=10; 
//         }
//         return (n==am);

//     }

//     int main (){
//         int n ;
//         cin >> n ;
//         cout << isArmstrong(n)?"am":"not am";
//     }

#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int original = n;
    int digits = log10(n) + 1; // Step 1: count number of digits
    int sum = 0;

    while (n > 0) {
        int digit = n % 10; // Step 2: get last digit
        sum += pow(digit, digits); // Step 3: add digit^digits to sum
        n /= 10; // Step 4: remove last digit
    }

    return sum == original; // Step 5: check if sum matches original number
}

int main() {
    int num;
    cin >> num; // Step 6: take input
    if (isArmstrong(num))
        cout << "Armstrong";
    else
        cout << "Not Armstrong";
}
