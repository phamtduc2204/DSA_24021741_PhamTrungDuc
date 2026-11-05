#include <iostream>

using namespace std;

// 1. SELECTION SORT (Sap xep chon)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 2. BUBBLE SORT (Sap xep noi bot)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// 3. INSERTION SORT (Sap xep chen)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 4. MERGE SORT (Sap xep tron)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tao mang phu de luu cac phan tu
    int L[100], R[100];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// 5. QUICK SORT (Sap xep nhanh)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chon phan tu cuoi lam pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Ham ho tro in mang
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Ham sao chep mang goc de test tung thuat toan
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int base[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(base) / sizeof(base[0]);
    int arr[100];

    copyArray(base, arr, n);
    selectionSort(arr, n);
    cout << "Selection Sort: ";
    printArray(arr, n);

    copyArray(base, arr, n);
    bubbleSort(arr, n);
    cout << "Bubble Sort:    ";
    printArray(arr, n);

    copyArray(base, arr, n);
    insertionSort(arr, n);
    cout << "Insertion Sort: ";
    printArray(arr, n);

    copyArray(base, arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Merge Sort:     ";
    printArray(arr, n);

    copyArray(base, arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Quick Sort:     ";
    printArray(arr, n);

    return 0;
}
