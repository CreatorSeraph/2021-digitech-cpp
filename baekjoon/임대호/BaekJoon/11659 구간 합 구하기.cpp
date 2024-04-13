#include <iostream>
#include <vector>

using namespace std;
int 구간합구하기4() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<int> v_sum(n);

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v[i] = input;

        if (i == 0) {
            v_sum[i] = input;
        } else {
            v_sum[i] = v_sum[i - 1] + input;
        }
    }

    int start, end;
    int sum;
    for (int i = 0; i < m; i++) {
        cin >> start >> end;

        sum = v_sum[end - 1];
        if (start - 2 >= 0)
            sum -= v_sum[start - 2];
        cout << sum << '\n';
    }

    return 0;
}
