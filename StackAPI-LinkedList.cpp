#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

int get(Node* head, int i) {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        if (count == i) return temp->data;
        count++;
        temp = temp->next;
    }
    return -1;
}

void insertHead(Node* &head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void deleteHead(Node* &head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Kiem tra rong
// Do phuc tap: O(1)
bool isEmpty(Node* head) {
    return head == nullptr;
}

// Lay kich thuoc
// Do phuc tap: O(1)
int size(int sz) {
    return sz;
}

// Chen mot phan tu vao stack
// Do phuc tap: O(1)
void push(Node* &head, int &sz, int item) {
    insertHead(head, item);
    sz++;
}

// Tra ve gia tri phan tu cuoi
// Do phuc tap: O(1)
int top(Node* head) {
    return get(head, 0);
}

// Xoa phan tu cuoi khoi stack va tra ve phan tu do
// Do phuc tap: O(1)
int pop(Node* &head, int &sz) {
    int val = top(head);
    deleteHead(head);
    sz--;
    return val;
}

// Test
int main() {
    Node* head = nullptr;
    int sz = 0;

    cout << "Kiem tra rong khi moi khoi tao: " << (isEmpty(head) ? "Rong" : "Khong rong") << endl;

    push(head, sz, 100);
    push(head, sz, 200);
    push(head, sz, 300);

    cout << "Kich thuoc stack: " << size(sz) << endl;
    cout << "Phan tu o dinh (top): " << top(head) << endl;
    cout << "Thuc hien pop: " << pop(head, sz) << endl;
    cout << "Phan tu o dinh sau khi pop: " << top(head) << endl;
    cout << "Kich thuoc con lai: " << size(sz) << endl;

    return 0;
}
