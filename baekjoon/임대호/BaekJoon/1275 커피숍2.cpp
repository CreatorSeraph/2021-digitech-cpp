#include <iostream>
#include <vector>

#define ull long long

using namespace std;

ull fill(vector<ull>& v, int*& arr, int start, int end, int index) {
    if (start == end) {
        v[index] = arr[start];
        return v[index];
    }

    v[index] = fill(v, arr, start, (start + end) / 2, index * 2)
               + fill(v, arr, (start + end) / 2 + 1, end, index * 2 + 1);

    return v[index];
}

ull get(vector<ull>& v, int start, int end, int findStart, int findEnd, int index) {
    if (start >= findStart && start <= findEnd && end >= findStart && end <= findEnd) {
        return v[index];
    }

    if (end < findStart || start > findEnd)
        return 0;

    int leftStart = start;
    int leftEnd = (start + end) / 2;

    int rightStart = (start + end) / 2 + 1;
    int rightEnd = end;

    return get(v, leftStart, leftEnd, findStart, findEnd, index * 2)
           + get(v, rightStart, rightEnd, findStart, findEnd, index * 2 + 1);
}

ull replace(vector<ull>& v, int start, int end, int index, int replaceArrIdx, int replaceValue) {
    if (end < replaceArrIdx || start > replaceArrIdx)
        return v[index];

    if (start == replaceArrIdx && end == replaceArrIdx) {
        v[index] = replaceValue;
        return v[index];
    }

    v[index] = replace(v, start, (start + end) / 2, index * 2, replaceArrIdx, replaceValue)
               + replace(v, (start + end) / 2 + 1, end, index * 2 + 1, replaceArrIdx, replaceValue);

    return v[index];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;

    cin >> n >> q;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ull> v(n * 4);
    fill(v, arr, 0, n - 1, 1);

    int x, y, a, b;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> a >> b;

        if (y < x) {
            int temp = x;
            x = y;
            y = temp;
        }

        cout << get(v, 0, n - 1, x - 1, y - 1, 1) << '\n';
        replace(v, 0, n - 1, 1, a - 1, b);
    }

    delete[] arr;

    return 0;
}
