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

Node* reverse(Node* head){
    Node * prev = nullptr;
    Node * current = head;
    while (current){
        Node* nextnode = current->next;
        current->next = prev ;
        prev = current ;
        current = nextnode;
    }
    return prev;
}

bool ispali(Node* head){
    if (!head || !head->next){
        return true;
    }
    Node * slow = head ;
    Node * fast = head ;

    while (fast->next && fast->next->next){
        slow = slow->next ;
        fast = fast->next ->next ;
    }
    Node * sechalf = reverse(slow->next);

    Node * p1 = head ;
    Node * p2 = sechalf;
    while (p2){
    if (p1->data != p2->data ){
        return false;
        break;
    }
    p1 = p1->next;
    p2 = p2->next;
    }
    slow -> next = reverse(sechalf);
    return true;
}
int main(){
    vector<int> arr = {1 , 1, 1, 1};
    Node* head = convertArr2LL(arr);

    // Print result
    if (ispali(head)){
        cout << "Palindrome" << endl;
    } else {
        cout << "No palindrome." << endl;
    }

    // Print linked list elements (only works if no cycle!)
    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
        
    }
    return 0;
}
