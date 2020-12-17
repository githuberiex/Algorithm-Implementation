#include <iostream>
using namespace std;

int partition(int *a, int low, int high) {
    int pivot = a[low]; //将第一个元素作为枢轴值，对表进行划分
    while (low < high) {
        while (low < high && pivot <= a[high])
            high--;
        a[low] = a[high]; //将比枢轴值小的移到左端
        while (low < high && pivot >= a[low])
            low++;
        a[high] = a[low]; //将比枢轴值大的移到右端
    }
    a[low] = pivot; //枢轴元素存放的最终位置
    return low;
}

void quickSort(int *a, int low, int high) {
    if (low < high) {
        int pivotPos = partition(a, low, high); //划分
        quickSort(a, low, pivotPos - 1);        //对子表递归排序
        quickSort(a, pivotPos + 1, high);
    }
}

int main() {
    int a[] = {5, 6, 8, 4, 3, 2, 7, 9, 1};
    int len = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, len - 1);
    for (int i = 0; i < len; i++)
        cout << a[i] << endl;
    return 0;
}