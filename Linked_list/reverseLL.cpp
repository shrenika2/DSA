#include <iostream>
#include <vector>

using namespace std ;

class Node{
public:
    int data ;
    Node* next;
public:
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i=1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head ;
}

Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* current = head ;
    while (current!=nullptr){
        Node* nextnode = current->next;
        current->next = prev ;
        prev = current ;
        current = nextnode;
    }
    return prev;
}

int main(){
    vector <int> arr = {30 , 5 , 8 , 7};
    Node* head = convertArr2LL(arr);
    head = reverseLL(head);
    Node* temp = head;
    while (temp){
        cout << temp->data<<" ";
        temp = temp -> next;
    }
    return 0;
}



