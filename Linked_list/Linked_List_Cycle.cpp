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

bool Linked_list_cycle(Node* head){
    if (head == nullptr || head->next == nullptr){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;           
        fast = fast->next->next;     // ✅ move 2 steps

        if (slow == fast){
            return true;             // cycle detected
        }
    }
    return false;                    // no cycle
}

int main(){
    vector<int> arr = {30, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    // Print result
    if (Linked_list_cycle(head)){
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle." << endl;
    }

    // Print linked list elements (only works if no cycle!)
    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
