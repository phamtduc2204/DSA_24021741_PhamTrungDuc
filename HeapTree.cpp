#include <iostream>
#include <algorithm> // Dùng hàm swap

using namespace std;

const int MAX = 1000; 

struct MaxHeap {
    int arr[MAX];
    int size = 0; 

 
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
    }


    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }


    void push(int val) {
        if (size == MAX) {
            cout << "Heap da day!\n";
            return;
        }
        arr[size] = val;     
        heapifyUp(size);    
        size++;
    }


    void pop() {
        if (size == 0) {
            cout << "Heap rong!\n";
            return;
        }
        arr[0] = arr[size - 1]; 
        size--;                 
        heapifyDown(0);         
    }

    
    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

 
    void buildHeap(int input[], int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            arr[i] = input[i];
        }
 
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }


    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    MaxHeap h;


    h.push(15);
    h.push(40);
    h.push(10);
    h.push(50);
    h.push(30);

    cout << "Heap sau khi them: ";
    h.print(); 

    cout << "Phan tu lon nhat: " << h.top() << "\n"; // 50


    h.pop();
    cout << "Heap sau khi pop: ";
    h.print(); 


    int a[] = {4, 10, 3, 5, 1};
    MaxHeap h2;
    h2.buildHeap(a, 5);
    cout << "Heap xay tu mang co san: ";
    h2.print(); 

    return 0;
}
