#include <iostream>
#include <vector>

using namespace std ;

class Node{
public:
    int data;
    Node* next;
    Node* back;
public:
    Node(int data1 , Node *next1 , Node* back1){
        data = data1 ;
        next = next1;
        back = back1;
    }
public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node * convert2Dll(vector <int> & arr){
    Node * head = new Node(arr[0]);
    Node * prev = head;
    for (int i=1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i] , nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node*head){
    while (head!=NULL){
        cout << head->data<<" ";
        head = head -> next;
    }
}
// brute force two pass solution
// tc= o(n) + o(n) = o(2n)
// sc = o(n)
Node* reverseDll(Node*head){
    vector<int> vals;

    Node* temp = head ;
    while (temp != nullptr){
        vals.push_back(temp->data);
        temp = temp -> next ;
    }

    temp = head ;
    int n = vals.size()-1;
    while (temp != nullptr){
        temp->data = vals[n--];
        temp = temp->next ;
    }
    return head ;
}

// optimal 
// tc = o(n)
// sc = o(1)
Node* rev_dll(Node*head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node * prev = NULL;
    Node* current = head;
    while (current != NULL){
        prev = current->back ;
        current->back = current->next ;
        current->next = prev ;

        current = current->back;
    }
    return prev->back ;
}

int main (){
    vector <int> arr={1 , 3, 4 , 5, 2};
    Node * head = convert2Dll(arr);
    print(head);
    cout << endl;
    head = rev_dll(head);
    
    print(head);
    return 0;
}