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

Node * removek(Node * head , int k){
    if (head == NULL) return head;
    if (k==1){
        Node * temp = head;
        head = head ->next;
        free (temp);
        return head;
    }
    int cnt = 0 ;
    Node* temp = head;
    Node* prev = NULL;
    while (temp!=NULL){
        cnt ++ ;
        if (cnt == k ){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
void print (Node* head){
    while (head!=NULL) {
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;

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

 
        head = removek(head , 5);
        print(head);
    
    return 0;
}