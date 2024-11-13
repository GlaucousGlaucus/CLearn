#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (arr[left] > arr[largest] && left < size) {
        largest = left;
    }
    if (arr[right] > arr[largest] && right < size) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Sort
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        // Bubble up the next largest element
        heapify(arr, i, 0);
    }
}

int getMax(const int arr[], const int n) {
    int max = arr[0];
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {};
    for (int i = 0; i < n; i++)
        count[arr[i] / exp % 10]++;
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] / exp % 10] - 1] = arr[i];
        count[arr[i] / exp % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    radixSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}

