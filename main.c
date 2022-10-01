#include "sort.h"
#include <stdio.h>

void my_sort(int *arr, int *cnt, int sort);

int main() {
    int n = 0;
    int sort = 0;
    printf("Введите размерность массива:\n");
    scanf("%d", &n);
    printf("Введите элементы массива через пробел:\n");
    int arr[n];
    input(arr, &n);
    printf("Выберите вариант сортировки: \n\
    1. Сортировка пузырьком O(N^2)\n\
    2. Быстрая сортировка O(Nlog(N))\n\
    3. Пирамидальная сортировка O(Nlog(N))\n");
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
    default:
        printf("Введите значение от 1 до 3");
        break;
    }
}