#include <iostream>
#include <vector>

using namespace std ;

class Node{
public:
    int data ;
    Node* next ;
    Node* back;
public:
    Node(int data1 , Node* next1 , Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
public:
    Node(int data1){
        data = data1;
        next = nullptr ;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* prev = head;
    for (int i=1 ; i < a.size() ; i++){
        Node* temp = new Node(a[i] , nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node*head){
    while (head->next != NULL){
        cout << head->data << " ";
        head = head-> next;
    }
}

Node* DeleteHead(Node*head){
    if (head == NULL || head->next == NULL){
        return NULL;
    }
    Node*prev = head;
    head = head->next;

    head -> back = nullptr;
    prev ->next = nullptr ;

    delete prev ;
    return head;
}

Node * DeleteTail(Node *head){
    if (head == NULL || head->next == NULL){
        return NULL;
    }
    Node * tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    Node*newTail = tail->back;
    newTail->next = nullptr ;
    tail->back=nullptr;
    delete tail;
    return head;
}

Node* removeKthElement(Node* head , int k){
    if (head == NULL){
        return NULL;
    }
    int cnt = 0 ;
    Node * kNode = head;
    while (kNode->next != NULL){
        cnt++;
        if (cnt == k) break;
        kNode= kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode -> next;

    if (prev == NULL && front == NULL){
        return NULL;
    }else if (prev == NULL){
         return DeleteHead(head);
    }else if (front == NULL){
        return DeleteTail(head);
    }else{
        prev->next = front;
        front->back = prev;

        kNode->next=nullptr;
        kNode->back= nullptr;
        delete(kNode);
        return head;
    }
}

int main (){
    vector <int> a= {1 , 5, 6, 7, 4, 3 ,5, 0};
    Node * head = convertArr2DLL(a);
    print(head);
    cout << endl;
    head = removeKthElement(head , 3);
    print(head);
 
}