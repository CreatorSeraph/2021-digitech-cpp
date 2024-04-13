#include <iostream>
#include <queue>
#include <vector>
#include <map>

struct Compare {
    bool operator() (int a, int b) {
        return a > b;
    }
};

using namespace std;
int 절댓값힙() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, Compare> pq;
    map<int, int> signedMap;

    int n;
    cin >> n;

    int pop;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;

        if (input != 0) {
            pq.push(abs(input));
            if (signedMap.find(input) != signedMap.end()) {
                signedMap.find(input)->second++;
            } else {
                signedMap.insert(make_pair(input, 1));
            }
        } else {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                pop = pq.top();
                pq.pop();

                auto find = signedMap.find(-pop);
                if (find != signedMap.end()) {
                    pop = -pop;
                    find->second--;

                    if (find->second == 0)
                        signedMap.erase(find);
                } else {
                    find = signedMap.find(pop);
                    find->second--;

                    if (find->second == 0)
                        signedMap.erase(find);
                }

                cout << pop << '\n';
            }
        }
    }

    return 0;
}
