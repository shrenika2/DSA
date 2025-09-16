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
        data = data1 ;
        next = nullptr;
    }
};

Node* array_ll(vector <int> & a){
    Node* head = new Node(a[0]);
    Node* current = head ;

    for (int i=1 ; i < a.size() ; i++){
        current ->next = new Node(a[i]);
        current = current->next;
    }
    return head ;
}

void print (Node* head){
    while (head!=NULL) {
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;

}

int middle(Node* head){
    if (head == nullptr){
        return -1;
    }
    int cnt = 0 ;
    Node* temp = head ;
    while (temp!=nullptr){
        cnt++;
        temp = temp -> next ;
    }

    int midInd = cnt/2;

    temp  = head ;

    for (int i=0 ; i < midInd ; i++){
        temp = temp->next ;
    }
    return temp->data;

}

int main (){
    vector <int> a = { 1 , 4 , 5, 7 , 2, 0};
    Node * head = array_ll(a);
    print(head);
    cout << middle(head);
    
    return 0;
}




