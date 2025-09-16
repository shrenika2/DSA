#include <iostream>
using namespace std ;

int gcd(int x , int y ){
    while (x>0 && y > 0){
        if (x>y) x=x%y;
        else y=y%x;
    }
    if (x==0) return y;
    return x;
}
int main (){
	int x ;
	cin >> x ;
	int y ;
	cin >> y ;

    cout << gcd(x,y);
}
// T C == O(log (0) min(x,y) )

