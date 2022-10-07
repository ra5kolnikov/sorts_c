#ifndef _SORT_H_
#define _SORT_H_

void swap(int *arr, int first, int second);
void quick_sort(int *arr, int size);
void bubble_sort(int *arr, int count);
void input(int *arr, int *n);
void output(int *arr, int *n);
void pyramid_sort(int *arr, int count, int first);
void heapSort(int *arr, int *cnt);
void heapify(int *arr, int count, int root);
void selection_sort(int *arr, int *count);
void insertion_sort(int *arr, int *count);

#endif // _SORT_H_
