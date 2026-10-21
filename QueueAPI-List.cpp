#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int get(int arr[], int i) {
    return arr[i];
}

void insertTail(int arr[], int &size, int value) {
    if (size >= MAX_SIZE) return;
    arr[size] = value;
    size++;
}

void deleteAt(int arr[], int &size, int i) {
    if (i < 0 || i >= size) return;
    for (int j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--;
}

void deleteHead(int arr[], int &size) {
    deleteAt(arr, size, 0);
}

// Kiem tra rong
// Do phuc tap: O(1)
bool isEmpty(int sz) {
    return sz == 0;
}

// Lay kich thuoc
// Do phuc tap: O(1)
int size(int sz) {
    return sz;
}

// Chen mot phan tu vao queue
// Do phuc tap: O(1)
void enqueue(int arr[], int &sz, int item) {
    insertTail(arr, sz, item);
}

// Tra ve gia tri phan tu dau trong queue
// Do phuc tap: O(1)
int front(int arr[]) {
    return get(arr, 0);
}

// Xoa phan tu dau khoi queue va tra ve phan tu do
// Do phuc tap: O(n)
int dequeue(int arr[], int &sz) {
    int val = front(arr);
    deleteHead(arr, sz);
    return val;
}

// Test
int main() {
	
    int arr[MAX_SIZE];
    int sz = 0;

    cout << "Kiem tra rong khi moi khoi tao: " << (isEmpty(sz) ? "Rong" : "Khong rong") << endl;

    enqueue(arr, sz, 10);
    enqueue(arr, sz, 20);
    enqueue(arr, sz, 30);

    cout << "Kich thuoc queue: " << size(sz) << endl;
    cout << "Phan tu o dau (front): " << front(arr) << endl;
    cout << "Thuc hien dequeue: " << dequeue(arr, sz) << endl;
    cout << "Phan tu o dau sau khi dequeue: " << front(arr) << endl;
    cout << "Kich thuoc con lai: " << size(sz) << endl;

    return 0;
}
