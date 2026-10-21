#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// 1. Truy cap phan tu tai vi tri i
// Do phuc tap: O(1)
int get(int arr[], int i) {
    return arr[i];
}

// 2. Chen vao vi tri i
// Do phuc tap: O(n)
void insertAt(int arr[], int &size, int i, int value) {
    if (size >= MAX_SIZE || i < 0 || i > size) return;
    for (int j = size; j > i; j--) {
        arr[j] = arr[j - 1]; 
    }
    arr[i] = value;
    size++;
}

// 3. Chen phan tu vao dau
// Do phuc tap: O(n)
void insertHead(int arr[], int &size, int value) {
    insertAt(arr, size, 0, value);
}

// 4. Chen phan tu vao cuoi
// Do phuc tap: O(1)
void insertTail(int arr[], int &size, int value) {
    if (size >= MAX_SIZE) return;
    arr[size] = value;
    size++;
}

// 5. Xoa vi tri i
// Do phuc tap: O(n)
void deleteAt(int arr[], int &size, int i) {
    if (i < 0 || i >= size) return;
    for (int j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1]; 
    }
    size--;
}

// 6. Xoa phan tu dau
// Do phuc tap: O(n)
void deleteHead(int arr[], int &size) {
    deleteAt(arr, size, 0);
}

// 7. Xoa phan tu cuoi
// Do phuc tap: O(1)
void deleteTail(int &size) {
    if (size > 0) {
        size--;
    }
}

// 8. Duyet xuoi
// Do phuc tap: O(n)
void traverseForward(int arr[], int size) {
    cout << "Duyet xuoi: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 9. Duyet nguoc
// Do phuc tap: O(n)
void traverseBackward(int arr[], int size) {
    cout << "Duyet nguoc: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Thêm phan tu
    insertTail(arr, size, 10);
    insertTail(arr, size, 20);
    insertHead(arr, size, 5);
    insertAt(arr, size, 2, 15); 

    // Duyet
    traverseForward(arr, size);
    traverseBackward(arr, size);

    // Truy cap
    cout << "Phan tu tai vi tri i = 2: " << get(arr, 2) << endl;

    // Xoa
    deleteHead(arr, size);
    deleteTail(size);
    deleteAt(arr, size, 0); 

    traverseForward(arr, size);

    return 0;
}
