#include <iostream>
using namespace std;

int a[] = {8, 5, 4, 9, 3, 7, 1, 2, 6};
int len = sizeof(a) / sizeof(a[0]);

void insertSort(int *a) {
    for (int i = 1; i < len; i++) { //将a[1]~a[len-1]插入到前面已排序的序列
        int temp = a[i];            //存放a[i]
        int j = i - 1;
        while (j >= 0 && temp < a[j]) { //从后往前查找插入位置
            a[j + 1] = a[j];            //向后挪一位
            j--;
        }
        a[j + 1] = temp;
    }
}

int main() {
    insertSort(a);
    for (int i = 0; i < len; i++)
        cout << a[i] << endl;
    return 0;
}