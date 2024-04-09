#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {12, 23, 34, 45, 56, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 45;

    int index = binarySearch(arr, 0, size - 1, key);

    if (index != -1)
        printf("Element found at index %d.\n", index);
    else
        printf("Element not found.\n");

    return 0;
}
