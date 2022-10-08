#include "sort.h"
#include <stdio.h>

void my_sort(int *arr, int *cnt, int sort);
void print_menu();

int main() {
    int n = 0;
    int sort = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter array elements separated by a space:\n");
    int arr[n];
    input(arr, &n);
    print_menu();
    scanf("%d", &sort);
    my_sort(arr, &n, sort);
    return 0;
}

void print_menu() {
    printf("Select a sort option:\n\
    1. Bubble sort O(n^2)\n\
    2. Selection sort O(n^2)\n\
    3. Insertion sort O(n^2)\n\
    4. Quick sort O(n log n)\n\
    5. MaxHeap sort O(n log n)\n\
    6. Merge sort O(n log n)\n");
}

void my_sort(int *arr, int *cnt, int sort) {
    switch (sort) {
    case 1:
        bubble_sort(arr, cnt);
        output(arr, cnt);
        break;
    case 2: 
        selection_sort(arr, cnt);
        output(arr, cnt);
        break;
    case 3: 
        insertion_sort(arr, cnt);
        output(arr, cnt);
        break;
    case 4: 
        quick_sort(arr, cnt);
        output(arr, cnt);
        break;
    case 5: 
        heapSort(arr, cnt);
        output(arr, cnt);
        break;
    case 6:
        merge_sort(arr, 0, cnt);
        output(arr, cnt);
        break;
    default:
        printf("Введите значение от 1 до 6");
        break;
    }
}