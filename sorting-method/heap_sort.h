#ifndef HEAP_SORT_HEADER
#define HEAP_SORT_HEADER

#include "../helper/utils.h"
//max heap
void down_heap(int a[], int n, int i) {
    int cur = a[i];
    while (i < n) {
        int child = (i << 1) | 1;
        if (child + 1 < n && a[child] < a[child + 1]) ++child;
        if (a[child] <= cur)
            break;
        a[i] = a[child];
        i = child;
    }
    a[i] = cur;
}
void heap_sort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        down_heap(a, n, i);
    int last = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        swap(a[i], a[0]);
        down_heap(a, i, 0);
    }
}

#endif