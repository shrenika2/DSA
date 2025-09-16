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

void deleteNode(Node*temp){
    Node * prev = temp->back;
    Node * front = temp -> next;

    if (front==NULL){
        prev -> next == nullptr;
        temp->back = nullptr ;
        free(temp);
        return ;
    }
    prev->next = front ;
    front->back = prev ;
    temp->next = temp->back = nullptr ;
    free(temp);
}

int main (){
    vector <int> a= {1 , 5, 6, 7, 4, 3 ,5, 0};
    Node * head = convertArr2DLL(a);
    print(head);
    cout << endl;
    deleteNode(head->next);
    print(head);
 
}