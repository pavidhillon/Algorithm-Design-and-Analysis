#include <iostream>
#include <climits>
using namespace std;

int Split(int* data, int left, int right) {
    int pivot = data[right];
    int marker = left - 1;

    for (int index = left; index < right; index++) {
        if (data[index] <= pivot) {
            marker++;
            swap(data[marker], data[index]);
        }
    }
    swap(data[marker + 1], data[right]);
    return marker + 1;
}

int RandomizedSplit(int* data, int left, int right) {
    int randomIndex = rand() % (right - left + 1) + left;
    swap(data[right], data[randomIndex]);
    return Split(data, left, right);
}

void RandomQuickSort(int* data, int left, int right) {
    if (left < right) {
        int pivotIndex = RandomizedSplit(data, left, right);
        RandomQuickSort(data, left, pivotIndex - 1);
        RandomQuickSort(data, pivotIndex + 1, right);
    }
}

void SortArray(int* data, int length) {
    RandomQuickSort(data, 0, length - 1);
}

int main() {
    int length;
    cin >> length;
    int* data = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> data[i];
    }

    SortArray(data, length);

    for (int i = 0; i < length; i++) {
        cout << data[i] << ";";
    }

    delete[] data;

    return 0;
}
