#include <iostream >
using namespace std ;

void rev(int arr[],int sz){
    int s=0, int e=sz-1;
    while (s<sz){
        swap(arr[s],arr[e]);
        s++;
        e--;

    }
}
int main (){
    int arr[]={1,2,3,4,5,6,7};
    int sz=7;
    rev(arr,sz);
    for (int i=0 ; i < sz ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}