#include <iostream>
using namespace std;

int a[] = {8, 5, 4, 9, 3, 7, 1, 2, 6};
int len = sizeof(a) / sizeof(a[0]);

void binaryInsertSort(int *a) {
    for (int i = 1; i < len; i++) { //将a[1]~a[len-1]折半插入到前面已排序的序列
        int low = 0;
        int high = i - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[i] <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        int tmp = a[i];
        for (int j = i; j > high + 1; j--)
            a[j] = a[j - 1];

        a[high + 1] = tmp;
    }
}

int main() {
    binaryInsertSort(a);
    for (int i = 0; i < len; i++)
        cout << a[i] << endl;
    return 0;
}