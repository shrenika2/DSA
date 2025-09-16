#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data ;
    Node* next;
    Node* back;

    Node(int data1 , Node* next1 , Node* back1){
        data = data1 ;
        next = next1;
        back = back1;
    }
    Node (int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node* array2LL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* mover = head;
    for (int i=0 ; i < a.size() ; i++){
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}


// brute force 
int lengthofll(Node* head){
    int cnt = 0 ;
    Node* temp = head ;
    while (temp){  
        cnt++;
        temp = temp->next;
    }
    int mid = (cnt /2) + 1 ;
    temp = head ;
    while (temp != NULL){
        mid = mid - 1 ;
        if (mid == 0){
            break;
        }
        temp = temp->next;
    }
    return temp ;
}

// optimal solution 
// tortoise & hare
// tc = o(n)
/// sc = o(1)
int midel(Node * head){
    Node* slow =head;
    Node* fast =head;
    while (fast!=NULL && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return slow->data;
}
