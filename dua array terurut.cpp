#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // Menambahkan elemen yang tersisa dari arr1
    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }

    // Menambahkan elemen yang tersisa dari arr2
    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    
    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    cout << "Array yang digabungkan: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

