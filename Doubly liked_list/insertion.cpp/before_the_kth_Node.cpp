#include <iostream>
#include <vector>

using namespace std ;

class Node{
public:
    int data ;
    Node* next;
    Node* back;
public:
    Node(int data1 , Node* next1 , Node* back1){
        data = data1 ;
        next = next1 ;
        back = back1 ;
    }
public:
    Node(int data1){
        data = data1;
        next = nullptr ;
        back = nullptr ;
    }
};

Node* arraytoDll(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* prev = head ;
    for (int i=1 ; i < a.size() ; i++){
        Node* temp = new Node(a[i] , nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head ;
}

void print(Node*head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

}

Node* before_Node(Node*node ,  int val){// node head
    Node* prev = node->back;
    Node* newNode = new Node(val , node , prev);
    prev->next = newNode;
    node->back = newNode;
    return prev ;// return head 

}

int main (){
    vector <int> a = {1, 4, 5, 6, 7, 0 ,4 , 2, 2};
    Node* head = arraytoDll(a);
    print(head);
    cout << "\n";
    head = before_Node(head->next, 90);
    print(head);

}
 