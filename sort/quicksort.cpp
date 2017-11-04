/*************************************************************************
	> File Name: quicksort.cpp
	> Author: JunHU
	> Mail: hujun09012@gmail.com
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int beg, int end) {
    int pivot = a[beg];
    int L = beg, R = end;
    while (R > L) {
        while (R > L && a[R] > pivot) R--;
        a[L] = a[R];
        while (R > L && a[L] < pivot) L++;
        a[R] = a[L];
    }
    a[L] = pivot;
    return L;
}
void quicksort(int a[], int beg, int end) {
    if (beg >= end) return;
    int mid = partition(a, beg, end);
    quicksort(a, beg, mid - 1);
    quicksort(a, mid + 1, end);
}
int main() {
    int a[10] = {1, 3, 2, 6, 5, 10, 4, 9, 8, 7};
    int n = 10;
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << ' '; 
    return 0;
}
