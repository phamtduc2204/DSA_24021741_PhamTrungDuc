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

void insertTail(Node* &head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
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

// Chen mot phan tu vao queue
// Do phuc tap: O(n)
void enqueue(Node* &head, int &sz, int item) {
    insertTail(head, item);
    sz++;
}

// Tra ve gia tri phan tu dau trong queue
// Do phuc tap: O(1)
int front(Node* head) {
    return get(head, 0);
}

// Xoa phan tu dau khoi queue va tra ve phan tu do
// Do phuc tap: O(1)
int dequeue(Node* &head, int &sz) {
    int val = front(head);
    deleteHead(head);
    sz--;
    return val;
}

// Test
int main() {
	
    Node* head = nullptr;
    int sz = 0;

    cout << "Kiem tra rong khi moi khoi tao: " << (isEmpty(head) ? "Rong" : "Khong rong") << endl;

    enqueue(head, sz, 100);
    enqueue(head, sz, 200);
    enqueue(head, sz, 300);

    cout << "Kich thuoc queue: " << size(sz) << endl;
    cout << "Phan tu o dau (front): " << front(head) << endl;
    cout << "Thuc hien dequeue: " << dequeue(head, sz) << endl;
    cout << "Phan tu o dau sau khi dequeue: " << front(head) << endl;
    cout << "Kich thuoc con lai: " << size(sz) << endl;

    return 0;
}
