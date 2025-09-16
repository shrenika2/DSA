#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i=1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* Delete_the_Middle_Node_of_a_Linked_List(Node* head){
    if (!head || !head->next) return nullptr;

    Node* slow = head ;
    Node* fast = head ;
    Node* prev = nullptr;

    while (fast!= nullptr && fast->next!=nullptr){
        prev = slow ;
        slow = slow->next ;
        fast = fast->next->next;
    }
    prev->next = slow->next ;
    return head ;
}

int main(){
    vector<int> arr = {30, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    head = Delete_the_Middle_Node_of_a_Linked_List(head );
    // Print linked list elements (only works if no cycle!)
    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
