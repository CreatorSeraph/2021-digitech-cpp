#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vector2 {
public:
    int x, y;
};

Vector2 toVec2(int x, int y) {
    Vector2 ret = {x, y};
    return ret;
}

int 유기농배추() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    int m, n, k;

    cin >> t;


    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;

        vector<vector<int> > v(m, vector<int>(n));

        int x_, y_;
        for (int j = 0; j < k; j++) {
            cin >> x_ >> y_;
            v[x_][y_] = 1;
        }

        int retCount = 0;
        int fillCount;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (v[x][y] != 1)
                    continue;

                v[x][y] = 0;
                queue<Vector2> posQueue;
                posQueue.push(toVec2(x, y));

                while (!posQueue.empty()) {
                    Vector2 pos = posQueue.front();
                    posQueue.pop();

                    if (pos.y > 0 && v[pos.x][pos.y - 1] == 1) {
                        v[pos.x][pos.y - 1] = 0;
                        posQueue.push(toVec2(pos.x, pos.y - 1));
                    }
                    if (pos.y < n - 1 && v[pos.x][pos.y + 1] == 1) {
                        v[pos.x][pos.y + 1] = 0;
                        posQueue.push(toVec2(pos.x, pos.y + 1));
                    }
                    if (pos.x > 0 && v[pos.x - 1][pos.y] == 1) {
                        v[pos.x - 1][pos.y] = 0;
                        posQueue.push(toVec2(pos.x - 1, pos.y));
                    }
                    if (pos.x < m - 1 && v[pos.x + 1][pos.y] == 1) {
                        v[pos.x + 1][pos.y] = 0;
                        posQueue.push(toVec2(pos.x + 1, pos.y));
                    }
                }
                retCount++;
            }
        }
        cout << retCount << '\n';
    }


    return 0;
}
