#include <iostream>

using namespace std;
int 히히1로만들기를풀었다() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int* arr = new int[n + 1];

    int time;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            arr[i] = 0;
            continue;
        }
        if (i == 2 || i == 3) {
            arr[i] = 1;
            continue;
        }

        time = 1000000;

        if (i % 3 == 0) {
            time = arr[(int)(i / 3)] + 1;
        }
        if (i % 2 == 0) {
            if (arr[(int)(i / 2)] + 1 < time) {
                time = arr[(int)(i / 2)] + 1;
            }
        }
        if (arr[i - 1] + 1 < time) {
            time = arr[i - 1] + 1;
        }

        arr[i] = time;
    }

    cout << arr[n];

    return 0;
}
