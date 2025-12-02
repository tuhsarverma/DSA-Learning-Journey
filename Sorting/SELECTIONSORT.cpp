#include <iostream>
using namespace std;

void SELECTIONSORT(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {

        int minindex = i;   // to compare with remaining elements

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }

        // swap smallest value with current index
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}

int main() {

    int n;
    cout << "enter the size";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SELECTIONSORT(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
