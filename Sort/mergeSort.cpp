#include <iostream>
using namespace std;

int a[] = {5, 6, 8, 4, 3, 2, 7, 9, 1};
int len = sizeof(a) / sizeof(a[0]);
int *b = (int *)malloc(len * sizeof(int)); //辅助数组

void merge(int *a, int low, int mid, int high) { //将两个有序表合并
    int i, j, k;
    for (k = 0; k < len; k++) //将a[]复制到b[]
        b[k] = a[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high;) { //将b[]的前半部分与后半部分比较并放入a[]
        if (b[i] < b[j])
            a[k++] = b[i++];
        else
            a[k++] = b[j++];
    }
    while (i <= mid)
        a[k++] = b[i++];
    while (j <= high)
        a[k++] = b[j++];
}

void mergeSort(int *a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);      //对左子序列递归排序
        mergeSort(a, mid + 1, high); //对右子序列递归排序
        merge(a, low, mid, high);
    }
}

int main() {
    mergeSort(a, 0, len - 1);
    for (int i = 0; i < len; i++)
        cout << a[i] << endl;
    return 0;
}