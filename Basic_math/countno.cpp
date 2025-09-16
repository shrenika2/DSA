#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1;  // log10(0) is undefined, so handle this case separately
    return log10(n) + 1;   // Efficient way to count digits
}

int main() {
    int n;
    cin >> n;
    cout << "Number of digits: " << countDigits(n);
    return 0;
}
