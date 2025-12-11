#include <iostream>
#include <vector>
using namespace std;    

class Solution {
public:
    int climstaris(int n) {
        if (n<=2) return 1 ;
        int prev2 = 1 ;
        int prev1 = 2 ;

        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

};
    
   int main (){
    int n ; 
    cin >> n ;

    Solution obj;

    cout << obj.climstaris(n);
    return 0;
   }