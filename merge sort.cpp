#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua sub-array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> leftArr(n1), rightArr(n2);
    
    // Menyalin data ke dalam array sementara
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    // Menggabungkan kembali array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Menyalin elemen yang tersisa dari leftArr, jika ada
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Menyalin elemen yang tersisa dari rightArr, jika ada
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Fungsi utama untuk melakukan Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid); // Urutkan bagian kiri
        mergeSort(arr, mid + 1, right); // Urutkan bagian kanan
        
        merge(arr, left, mid, right); // Gabungkan dua bagian yang terurut
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Array sebelum diurutkan: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, arr.size() - 1); // Panggil mergeSort
    
    cout << "Array setelah diurutkan: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

