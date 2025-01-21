#include <iostream>
#include <vector>

using namespace std;

int fill(vector<int>& v, int*& arr, int start, int end, int index) {
    if (start == end) {
        v[index] = start;
        return v[index];
    }

    int left = fill(v, arr, start, (start + end) / 2, index * 2);
    int right = fill(v, arr, (start + end) / 2 + 1, end, index * 2 + 1);

    if (arr[left] < arr[right]) {
        v[index] = left;
        return left;
    } else if (arr[left] > arr[right]) {
        v[index] = right;
        return right;
    } else {
        int ret = min(left, right);
        v[index] = ret;
        return ret;
    }
}

int replace(vector<int>& v, int*& arr, int start, int end, int index, int replaceArrIdx, int replaceValue) {
    if (end < replaceArrIdx || start > replaceArrIdx)
        return v[index];

    if (start == replaceArrIdx && end == replaceArrIdx) {
        arr[start] = replaceValue;
        v[index] = start;
        return v[index];
    }

    int left = replace(v, arr, start, (start + end) / 2, index * 2, replaceArrIdx, replaceValue);
    int right = replace(v, arr, (start + end) / 2 + 1, end, index * 2 + 1, replaceArrIdx, replaceValue);

    if (arr[left] < arr[right]) {
        v[index] = left;
        return left;
    } else if (arr[left] > arr[right]) {
        v[index] = right;
        return right;
    } else {
        int ret = min(left, right);
        v[index] = ret;
        return ret;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> v(n * 4);
    fill(v, arr, 0, n - 1, 1);

    int m;
    cin >> m;

    char c;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c == '1') {
            cin >> a >> b;
            replace(v, arr, 0, n - 1, 1, a - 1, b);
        } else if (c == '2') {
            cout << v[1] + 1 << '\n';
        }
    }

    delete[] arr;

    return 0;
}
