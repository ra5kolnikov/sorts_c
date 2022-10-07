#include "sort.h"
#include <stdio.h>

void my_sort(int *arr, int *cnt, int sort);

int main() {
    int n = 0;
    int sort = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter array elements separated by a space:\n");
    int arr[n];
    input(arr, &n);
    printf("Select a sort option:\n\
    1. Bubble sort O(N^2)\n\
    2. Quick sort O(Nlog(N))\n\
    3. MaxHeap sort O(Nlog(N))\n\
    4. Selection sort O(N^2)\n\
    5. Insertion sort O(N^2)\n");
    scanf("%d", &sort);
    my_sort(arr, &n, sort);
    return 0;
}

void my_sort(int *arr, int *cnt, int sort) {
    switch (sort) {
    case 1:
        bubble_sort(arr, *cnt);
        output(arr, cnt);
        break;
    case 2: 
        quick_sort(arr, *cnt);
        output(arr, cnt);
        break;
    case 3: 
        heapSort(arr, cnt);
        output(arr, cnt);
        break;
    case 4: 
        selection_sort(arr, cnt);
        output(arr, cnt);
        break;
    case 5: 
        insertion_sort(arr, cnt);
        output(arr, cnt);
        break;
    default:
        printf("Введите значение от 1 до 5");
        break;
    }
}