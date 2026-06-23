#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Avoid division by zero
        if (arr[high] == arr[low]) {
            if (arr[low] == target)
                return low;
            return -1;
        }

        // Estimate the position
        int pos = low + ((double)(target - arr[low]) * (high - low)) /
                            (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 50;
    int index = interpolationSearch(arr, n, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
