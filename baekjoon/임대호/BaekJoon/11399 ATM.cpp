#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;
int ATM() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int sum = 0;
    int* result = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            result[i] += arr[j];
        }

        sum += result[i];
    }

    cout << sum;

    return 0;
}
