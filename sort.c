#include <stdio.h>
#include "sort.h"

void input(int *arr, int *n) {
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void output(int *arr, int *n) {
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int count) {
    for (int i = 0; i < count - 1 ; i++) {
        for (int j = (count - 1); j > i; j--) {
            if(arr[i] > arr[j]) {
                swap(arr, i, j);
            }
        }
    }
}

void quick_sort(int *arr, int size) {
    int left = 0;
    int right = size - 1;
    int mid = arr[size / 2];
    while (left <= right) {
        while (arr[left] < mid) {
            left++;
        }
        while (arr[right] > mid) {
            right--;
        }
        if (left <= right) {
            swap(arr, left, right);
            left++;
            right--;
        }
    }
    if (right > 0) {
        quick_sort(arr, right + 1);
    }
    if (left < size) {
        quick_sort(&arr[left], size - left);
    }
}

void swap(int *arr, int first, int second) {
    int tmp = 0;
    tmp = arr[second];
    arr[second] = arr[first];
    arr[first] = tmp;
}

void heapify(int *arr, int cnt, int root) {
    int max = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    if (left < cnt && arr[left] > arr[max]) {
        max = left;
    }
    
    if (right < cnt && arr[right] > arr[max]) {
        max = right;
    }

    if (max != root) {
        swap(arr, root, max);
        heapify(arr, cnt, max);
    }
}

void heapSort(int *arr, int *cnt) {
    for (int i = *cnt / 2 - 1; i >= 0; i--) {
        heapify(arr, *cnt, i);
    }

    for (int i = *cnt - 1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}