#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* array2Dll(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        // If only one node, delete it and return NULL
        delete head;
        return NULL;
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;
    delete tail;

    return head;
}

int main() {
    vector<int> a = {1, 6, 3, 0, 2, 5, 9};
    Node* head = array2Dll(a);

    print(head);

    head = deleteTail(head); // Update head after deletion
    print(head);

    return 0;
}
