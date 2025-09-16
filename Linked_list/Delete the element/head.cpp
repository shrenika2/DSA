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

void print (Node* head){
    while (head!=NULL) {
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;

}

Node* removesHead(Node*head){
    if (head == NULL) return head ;
    Node * temp = head ;
    head = head -> next;
    delete temp ;
    return head ;
}
int main (){
    vector <int> a = { 1 , 4 , 5, 7 , 2, 0};
    Node* head = new Node(a[0]);
    Node * current = head ;

    for (int i=1 ; i < a.size() ; i++){
        current ->next = new Node(a[i]);
        current = current->next;
    }
    print(head);

 
        head = removesHead(head);
        print(head);
    
    return 0;
}




