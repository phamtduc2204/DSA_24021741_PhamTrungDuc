#include <iostream>
using namespace std;

struct Node {
    int data;    
    Node* next;   
};

// Tao mot Node moi
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// 1. Truy cap phan tu tai vi tri i
// Do phuc tap thoi gian: O(n)
int get(Node* head, int i) {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        if (count == i) return temp->data; 
        count++;
        temp = temp->next;
    }
    cout << "Vi tri i khong hop le!" << endl;
    return -1;
}

// 2. Chen phan tu vao dau
// Do phuc tap thoi gian: O(1)
void insertHead(Node* &head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head; 
    head = newNode;
}

// 3. Chen phan tu vao cuoi
// Do phuc tap thoi gian: O(n)
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

// 4. Chen phan tu vao vi tri i
// Do phuc tap thoi gian: O(n)
void insertAt(Node* &head, int i, int value) {
    if (i == 0) {
        insertHead(head, value);
        return;
    }
    Node* temp = head;
    for (int k = 0; k < i - 1 && temp != nullptr; k++) { 
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Vi tri chen khong hop le!" << endl;
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// 5. Xoa phan tu dau
// Do phuc tap thoi gian: O(1)
void deleteHead(Node* &head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next; 
    delete temp;
}

// 6. Xoa phan tu cuoi
// Do phuc tap thoi gian: O(n)
void deleteTail(Node* &head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) { 
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// 7. Xoa vi tri i
// Do phuc tap thoi gian: O(n)
void deleteAt(Node* &head, int i) {
    if (head == nullptr) return;
    if (i == 0) {
        deleteHead(head);
        return;
    }
    Node* temp = head;
    for (int k = 0; k < i - 1 && temp->next != nullptr; k++) { 
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Vi tri xoa khong hop le!" << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// 8. Duyet xuoi
// Do phuc tap thoi gian: O(n)
void traverseForward(Node* head) {
    cout << "Duyet xuoi: ";
    Node* temp = head;
    while (temp != nullptr) { // O(n)
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 9. Duyet nguoc
// Do phuc tap thoi gian: O(n)
void traverseBackward(Node* head) {
    if (head == nullptr) return;
    traverseBackward(head->next); 
    cout << head->data << " ";     
}

int main() {
    Node* head = nullptr; 

    // Them phan tu
    insertTail(head, 10); 
    insertTail(head, 20); 
    insertHead(head, 5);  
    insertAt(head, 2, 15); 

    // Duyet xuoi + nguoc
    traverseForward(head);  

    cout << "Duyet nguoc: ";
    traverseBackward(head); 
    cout << endl;

    // Truy cap
    cout << "Phan tu tai vi tri i = 2: " << get(head, 2) << endl; 

    // Xoa phan tu
    deleteHead(head); 
    deleteTail(head); 
    deleteAt(head, 0); 

    traverseForward(head); 

    return 0;
}
