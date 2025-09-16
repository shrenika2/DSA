#include <iostream>
using namespace std;

int reverse(int n) {
    if (n == 0) return 0;

    int sign = (n < 0) ? -1 : 1;  
    n = abs(n);                  

    int rn = 0;
    while (n > 0) {
        int ld = n % 10;
        rn = rn * 10 + ld;
        n /= 10;
    }

    return sign * rn;  
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
}
