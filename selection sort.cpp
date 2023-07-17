#include <iostream>
using namespace std;

class SelectionSort {
private:
    int* arr;
    int size;

public:
    SelectionSort(int* array, int length) {
        arr = array;
        size = length;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap elements
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    void display() {
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort sorter(arr, size);
    sorter.sort();
    sorter.display();

    return 0;
}
