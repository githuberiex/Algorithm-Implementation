#include <iostream>
using namespace std;

int horspool(string s, string p) {
    int len_s = s.size(); //文本长度
    int len_p = p.size(); //模式长度
    int i = 0;
    int count = 1;
    while (len_s > 0 && len_p > 0 && i <= (len_s - len_p)) {
        int k;
        int j = len_p - 1;
        while (j >= 0 && p[j] == s[i + j]) // p与s从右往左匹配
            j--;
        if (j == -1) //匹配成功，返回对应位置i
            return i;
        else { //匹配不成功
            int flag = 0;
            j = len_p - 1;
            for (k = j - 1; k >= 0; k--)
                if (p[k] == s[i + j]) {
                    flag = 1;
                    break;
                }
            if (flag)          // p前len_p-1中出现s[i+j]这个元素
                i = i + j - k; //右移j-k长度
            else               // p前len_p-1中未现s[i+j]这个元素
                i += len_p;    //右移len_p长度
        }
        count++;
    }
    return -1; //完成所有匹配后未匹配成功,返回-1
}

int main() {
    string text = "FAILUREEISATHEBMOTHERCCFDSUCCESS";
    string pattern = "SUCCESS";
    cout << horspool(text, pattern);
    return 0;
}
