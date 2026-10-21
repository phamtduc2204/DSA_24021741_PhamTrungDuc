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

void deleteTail(int &size) {
    if (size > 0) {
        size--;
    }
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

// Chen mot phan tu vao stack
// Do phuc tap: O(1)
void push(int arr[], int &sz, int item) {
    insertTail(arr, sz, item);
}

// Tra ve gia tri phan tu cuoi
// Do phuc tap: O(1)
int top(int arr[], int sz) {
    return get(arr, sz - 1);
}

// Xoa phan tu cuoi khoi stack va tra ve phan tu do
// Do phuc tap: O(1)
int pop(int arr[], int &sz) {
    int val = top(arr, sz);
    deleteTail(sz);
    return val;
}

//Test
int main() {
    int arr[MAX_SIZE];
    int sz1 = 0;

    cout << "Kiem tra rong khi moi khoi tao: " << (isEmpty(sz1) ? "Rong" : "Khong rong") << endl;

    push(arr, sz1, 10);
    push(arr, sz1, 20);
    push(arr, sz1, 30);

    cout << "Kich thuoc stack: " << size(sz1) << endl;
    cout << "Phan tu o dinh (top): " << top(arr, sz1) << endl;
    cout << "Thuc hien pop: " << pop(arr, sz1) << endl;
    cout << "Phan tu o dinh sau khi pop: " << top(arr, sz1) << endl;
    cout << "Kich thuoc con lai: " << size(sz1) << endl;


    return 0;
}
