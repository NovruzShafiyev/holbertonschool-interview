#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @a: The first element
 * @b: The second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Ensure the subtree rooted at index i is a heap
 * @array: The array
 * @n: The size of the heap
 * @i: The root index of the subtree
 * @size: The total size of the array (for printing purposes)
 */
void heapify(int *array, size_t n, size_t i, size_t size)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, n, largest, size);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    for (ssize_t i = (size / 2) - 1; i >= 0; i--)
        heapify(array, size, i, size);

    for (ssize_t i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0, size);
    }
}
