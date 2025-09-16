#include <iostream>
using namespace std ;

class Arraystack{
private:
    int arr[1000];
    int topindex;

public:
    Arraystack(){
        topindex=-1;
    }

    void push (int x ){
        if (topindex==999){
            return ;
        }
        arr[++topindex]=x;
    }

    int top(){
        if (topindex==-1){
            return -1;
        }
        return arr[topindex];
    }
    int pop(){
        if (topindex==-1){
            return -1;
        }
        return arr[topindex--];
    }

    bool isEmpty(){
        return topindex==-1;
    }

};
