#include<iostream>
using namespace std ;

class ArrayQueue {
private:
    int arr[1000];
    int front , rear ;
    int size;
public:
    ArrayQueue() {
        front = 0 ;
        rear = -1 ;
        size = 0 ;
    }
    
    void push(int x) {
        if (size==1000){
            return ;
        }
        rear =(rear + 1) % 1000;
        arr[rear]=x;
        size++;
    }
    
    int pop() {
        if (size==0){
            return -1;
        }
        int val = arr[front];
        front = (front+1) % 1000;
        size--;
        return val;
    }
    
    int peek() {
        return arr[front];   
    }
    
    bool isEmpty() {
        return size==0;
    }
};
