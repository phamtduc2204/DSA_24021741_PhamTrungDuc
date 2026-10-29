#include <iostream>
using namespace std;

const int SIZE = 7;
int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
}

void insert(int key) {
    int i = 0;
    while (i < SIZE) {
        int idx = (key + i) % SIZE;
        if (hashTable[idx] == -1 || hashTable[idx] == -2) {
            hashTable[idx] = key;
            return;
        }
        i++; 
    }
}

bool search(int key) {
    int i = 0;
    while (i < SIZE) {
        int idx = (key + i) % SIZE;
        if (hashTable[idx] == key) return true;
        if (hashTable[idx] == -1) return false;
        i++;
    }
    return false;
}

void removeKey(int key) {
    int i = 0;
    while (i < SIZE) {
        int idx = (key + i) % SIZE;
        if (hashTable[idx] == key) {
            hashTable[idx] = -2; 
            return;
        }
        if (hashTable[idx] == -1) return;
        i++;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        if (hashTable[i] == -1) cout << "<TRONG>\n";
        else if (hashTable[i] == -2) cout << "<DA XOA>\n";
        else cout << hashTable[i] << "\n";
    }
}

int main() {
    init();

    insert(10); // 10 % 7 = 3
    insert(17); // 17 % 7 = 3 
    insert(24); // 24 % 7 = 3 

    display();

    removeKey(17);
    cout << "\n--- Sau khi xóa 17 ---\n";
    display();

    cout << "\nKiem tra 24: " << (search(24) ? "Co" : "Khong") << "\n";

    return 0;
}
