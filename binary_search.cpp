#include <iostream>
using namespace std;

int binarySearch(int arr[], int x, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (x == arr[mid]) {
        return mid;
    }
    else if (x > arr[mid]) {
        return binarySearch(arr, x, mid + 1, high);
    }
    else {
        return binarySearch(arr, x, low, mid - 1);
    }
}
int main() {
    int arr[] = {100, 200, 300, 400, 500, 600, 700,800, 900};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x;
    cout << "Enter the number to search: ";
    cin >> x;

    int result = binarySearch(arr, x, 0, n - 1);

    if (result != -1) {
        cout << "Element found at index " << result;
    }
    else {
        cout << "Element not found";
    }

    return 0;
}
