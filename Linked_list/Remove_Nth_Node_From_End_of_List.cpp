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

Node* Remove_Nth_Node_From_End_of_List(Node* head , int n){
    if (!head) return nullptr;
    Node* dummy =new Node(0);
    dummy->next = head;

    Node* slow = dummy ;
    Node* fast = dummy ;

    for (int i=0 ; i <= n ; i++){
        fast = fast -> next ;
    }
    while (fast!= nullptr){
        slow = slow->next ;
        fast = fast->next;
    }
    slow -> next = slow -> next -> next;
    return dummy-> next ;

}

int main(){
    vector<int> arr = {30, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    head = Remove_Nth_Node_From_End_of_List(head , 2);
    // Print linked list elements (only works if no cycle!)
    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
