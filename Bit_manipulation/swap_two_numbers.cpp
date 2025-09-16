#include <iostream>
#include <vector>

using namespace std ;

class Solution {
public:
    void swap(int &a, int &b) {
        // Your code goes here
        if (a!=b){
        a= a^b;
        b=a^b;
        a=a^b;}
        
    }
};