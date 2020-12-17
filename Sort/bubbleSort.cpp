#include <iostream>
using namespace std;

int a[] = {8, 5, 4, 9, 3, 7, 1, 2, 6};
int len = sizeof(a) / sizeof(a[0]);

void bubbleSort(int *a) {
    for (int i = 0; i < len - 1; i++) { // n-1次比较，n-1次循环
        int flag = 0;
        for (int j = 0; j < len - 1 - i; j++) { //每次从头比较
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag++;
            }
        }
        if (flag == 0)
            break;
    }
}

int main() {
    bubbleSort(a);
    for (int i = 0; i < len; i++)
        cout << a[i] << endl;
    return 0;
}