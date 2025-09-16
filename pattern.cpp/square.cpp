// // #include<iostream>
// // using namespace std;
// // int main (){
// //     int n;
// //     cin >> n ;
// //     for (int i=1 ; i <= n ; i++){
// //         for (int j=1 ; j <= n ; j++){
// //             cout << "*"  << " ";
// //         }
// //         cout << endl;
// //     }
// //     return 0;
    
// // }
// // #include<iostream>
// // using namespace std;
// // int main (){
// //     int n;
// //     cin >> n ;
// //     for (int i=1 ; i <= n ; i++){
// //         for (int j=1 ; j <= n ; j++){
// //             cout << i << " ";
// //         }
// //         cout << endl;
// //     }
// //     return 0;
    
// // }

// // #include<iostream>
// // using namespace std;
// // int main (){
// //     int n;
// //     cin >> n ;
// //     for (int i=1 ; i <= n ; i++){
// //         for (int j=1 ; j <= n ; j++){
// //             cout << j << " ";
// //         }
// //         cout << endl;
// //     }
// //     return 0;
    
// // }
// // #include<iostream>
// // using namespace std;
// // int main (){
// //     int n;
// //     cin >> n ;
// //     for (int i=1 ; i <= n ; i++){
// //  char ch ='A';
// //         for (int j=1 ; j <= n ; j++){
// //             cout << ch  << " ";
// //             ch=ch+1;
// //         }
// //         cout << endl;
// //     }
// //     return 0;
    
// // }
// // #include<iostream>
// // using namespace std;
// // int main (){
// //     int n;
// //     cin >> n ;
// //     int num=1;
// //     for (int i=1 ; i <= n ; i++){
// //         for (int j=1 ; j <= n ; j++){
// //             cout << num << " ";
// //             num++;
// //         }
// //         cout << endl;
// //     }
// //     return 0;
    
// // }


// #include <iostream>
// using namespace std ;
// int square(int n ){
//     for (int i=0 ; i < n ; i++){
//         for (int j=0 ; j < n ; j++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }
// int main (){
//     int n ;
//     cin >> n ;
//     cout << square(n);
// }



#include <iostream>
using namespace std ;
void triangle(int n) {
    for (int i = 1; i <=n; i++) {  // Loop for rows
        for (int j = n-i+1; j >=0 ; j--) {  // Loop for columns
            cout  << " ";  // Convert ASCII value to character
        }
        for (int j=0 ; j < i ; j++){
            cout << char('A'+j) << " ";
        }
        cout << endl;
    }
}
int main (){
    int n ;
    cin >> n ;
    triangle(n);
    return 0;
}