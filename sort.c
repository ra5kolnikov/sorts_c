#include <stdio.h>
#include "sort.h"

void input(int *arr, int *n) {
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void output(int *arr, int *n) {
    for (int i = 0; i < *n; i++) {
        printf("%d", arr[i]);
        if (i != *n - 1) {
            printf(" ");
        }
    }
}

void bubble_sort(int *arr, int *count) {
    int counter = 0;
    int j = 0;
    do {
        counter = 0;
        for (int i = 0; i < *count; i++) {
            j = i + 1;
            if (arr[i] > arr[j]) {
                swap(arr, i, j);
                counter++;
            }
        }
    } while (counter > 0);
}

void selection_sort(int *arr, int *count) {
    int min = 0;
    for (int i = 0; i < *count - 1; i++) {
        min = i;
        for (int j = i + 1; j < *count; j++) 
            if(arr[j] < arr[min]) {
                min = j;
            }
        if (min != i) {
            swap(arr, i, min);
        }
    }
}

void insertion_sort(int *arr, int *count) {
    int newElement, location;
 
    for (int i = 1; i < *count; i++) {
        newElement = arr[i];
        location = i - 1;
        while(location >= 0 && arr[location] > newElement) {
            arr[location + 1] = arr[location];
            location = location - 1;
        }
        arr[location + 1] = newElement;
    }
}

void quick_sort(int *arr, int *size) {
    int left = 0;
    int right = *size - 1;
    int mid = arr[*size / 2];
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
        quick_sort(arr, &right + 1);
    }
    if (left < *size) {
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

void merge_sort(int *arr, int start, int *end) {
    if (*end > start){
        int midle = (start + *end)/2;
        merge_sort(arr, start, &midle);
        merge_sort(arr, midle + 1,end);
        merge(arr, start, midle, midle + 1, *end);
    }
}

void merge(int *arr, int start, int midLeft, int midRight, int end) {
    int newArray[end - start + 1];
    int i = start;
    int j = midRight;
    int z = 0;
    int n = end - start + 1;
    while (z < n) {
        if (arr[i] <= arr[j] && i <= midLeft && j <= end) {
            newArray[z] = arr[i];
            z++;
            i++;
        }
        if (arr[j] <= arr[i] && i <= midLeft && j <= end) {
            newArray[z] = arr[j];
            z++;
            j++;
        }
        if (i > midLeft && j <= end) {
            newArray[z] = arr[j];
            z++;
            j++;
        }
        if (j > end && i <= midLeft) {
            newArray[z] = arr[i];
            z++;
            i++;
        }
    }

    for (int i = 0, j = start; j <= end; i++, j++) {
        arr[j] = newArray[i];
    }
}
