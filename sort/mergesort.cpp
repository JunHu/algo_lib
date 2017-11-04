/*************************************************************************
	> File Name: mergesort.cpp
	> Author: JunHU
	> Mail: hujun09012@gmail.com
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int beg, int mid, int end) {
    vector<int> temp;
    int L = beg, R = mid + 1;
    while (L <= mid && R <= end) {
        if (a[L] < a[R]) temp.push_back(a[L++]);
        else temp.push_back(a[R++]);
    }
    while (L <= mid) temp.push_back(a[L++]);
    while (R <= end) temp.push_back(a[R++]);
    for (int i = 0; i < temp.size(); ++i) a[beg + i] = temp[i];
}
void mergesort(int a[], int beg, int end) {
    if (beg >= end) return;
    int mid = (beg + end) >> 1;
    mergesort(a, beg, mid);
    mergesort(a, mid + 1, end);
    merge(a, beg, mid, end);
}
int main() {
    int a[10] = {1, 3, 2, 6, 5, 10, 4, 9, 8, 7};
    int n = 10;
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << ' '; 
    return 0;
}
