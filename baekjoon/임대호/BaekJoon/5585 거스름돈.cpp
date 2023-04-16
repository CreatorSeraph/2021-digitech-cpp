#include <iostream>

using namespace std;
const int PRICE = 1000;
int 거스름돈() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int i = 0;

    cin >> i;

    int remain = PRICE - i;

    int ret = 0;
    ret += remain / 500;
    remain = remain % 500;

    ret += remain / 100;
    remain = remain % 100;

    ret += remain / 50;
    remain = remain % 50;

    ret += remain / 10;
    remain = remain % 10;

    ret += remain /  5;
    remain = remain % 5;

    ret += remain;

    cout << ret;

    return 0;
}