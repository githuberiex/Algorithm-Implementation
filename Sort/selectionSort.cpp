#include <iostream>
using namespace std;

int a[] = {8, 5, 4, 9, 3, 7, 1, 2, 6};
int len = sizeof(a) / sizeof(a[0]);

void selectSort(int *a) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (a[min] > a[j])
                min = j;
        }
        swap(a[min], a[i]);
    }
}

int main() {
    selectSort(a);
    for (int i = 0; i < len; i++)
        cout << a[i] << endl;
    return 0;
}