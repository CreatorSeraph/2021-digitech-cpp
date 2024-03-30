#include <iostream>

using namespace std;
int 동전0() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int value = 0;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (k >= arr[i]) {
            value += (int)(k / arr[i]);
            k %= arr[i];
        }
    }

    cout << value;

    return 0;
}
