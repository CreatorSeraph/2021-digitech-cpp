#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator() (int a, int b) {
        return a > b;
    }
};

int 최소힙() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, Compare> pq;

    int n;
    cin >> n;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input > 0) {
            pq.push(input);
        } else {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}
