#include <iostream>
#include <map>

using namespace std;
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, b;

    cin >> n >> m >> b;

    int* arr = new int[n * m];
    for (int i = 0; i < n * m; i++) {
        cin >> arr[i];
    }

    return 0;
}
