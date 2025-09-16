#include <iostream>
using namespace std;

// int reverse(int n) {
//     if (n == 0) return 0;

//     int sign = (n < 0) ? -1 : 1;  
//     n = abs(n); 
//     int nnn=n;                 

//     int rn = 0;
//     while (n > 0) {
//         int ld = n % 10;
//         rn = rn * 10 + ld;
//         n /= 10;
//     }

//     int nn= sign * rn; 
//     if (nn==nnn) return true;
//      else return false;
    
    
// }

bool isPalindrome(int n) {
    // Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes
    if (n < 0 || (n % 10 == 0 && n != 0))
        return false;

    int reversedHalf = 0;
    while (n > reversedHalf) {
        reversedHalf = reversedHalf * 10 + n % 10;
        n /= 10;
    }

    // Check equality (even or odd number of digits)
    return (n == reversedHalf) || (n == reversedHalf / 10);
}

int main() {
    int n;
    cin >> n;
    cout << isPalindrome(n)?"pali":"not pali";
}
