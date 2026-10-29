#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    int data;
    Node* next;
};

Node* hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = nullptr;
}

void insert(int key) {
    int idx = key % SIZE;
    
    Node* newNode = new Node;
    newNode->data = key;
    newNode->next = hashTable[idx]; 
    
    hashTable[idx] = newNode;       
}

bool search(int key) {
    int idx = key % SIZE;
    Node* temp = hashTable[idx];
    
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

void removeKey(int key) {
    int idx = key % SIZE;
    Node* temp = hashTable[idx];
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == key) {
            if (prev == nullptr) hashTable[idx] = temp->next; 
            else prev->next = temp->next;                    
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* temp = hashTable[i];
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    init();

    insert(10); // 10 % 7 = 3
    insert(17); // 17 % 7 = 3 
    insert(24); // 24 % 7 = 3 

    display();

    cout << "\nKiem tra 17: " << (search(17) ? "Co" : "Khong") << "\n";

    removeKey(17);
    cout << "\n--- Sau khi xoa 17 ---\n";
    display();

    return 0;
}
