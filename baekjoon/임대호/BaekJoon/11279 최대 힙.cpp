#include <iostream>
#include <queue>

using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int> pq;

    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;

        if (v == 0) {
            if (pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(v);
        }
    }

	return 0;
}