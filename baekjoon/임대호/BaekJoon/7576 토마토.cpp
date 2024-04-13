#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct Vector3 {
public:
    int x, y;
};
Vector2 toVec2(int x, int y) {
    Vector2 ret = {x, y};
    return ret;
}

int 토마토1() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int>(m));

    int input;

    queue<Vector2> q;

    for (int y = m - 1; y >= 0; y--) {
        for (int x = 0; x < n; x++) {
            cin >> input;
            v[x][y] = input;

            if (input == 1) {
                q.push(toVec2(x, y));
            }
        }
    }

    Vector2 pos;
    list<Vector2> addList;

    int day = 0;
    while (true) {
        addList.clear();

        while (!q.empty()) {
            pos = q.front();
            q.pop();

            if (pos.y > 0 && v[pos.x][pos.y - 1] == 0) {
                v[pos.x][pos.y - 1] = 1;
                addList.push_back(toVec2(pos.x, pos.y - 1));
            }
            if (pos.y < m - 1 && v[pos.x][pos.y + 1] == 0) {
                v[pos.x][pos.y + 1] = 1;
                addList.push_back(toVec2(pos.x, pos.y + 1));
            }
            if (pos.x > 0 && v[pos.x - 1][pos.y] == 0) {
                v[pos.x - 1][pos.y] = 1;
                addList.push_back(toVec2(pos.x - 1, pos.y));
            }
            if (pos.x < n - 1 && v[pos.x + 1][pos.y] == 0) {
                v[pos.x + 1][pos.y] = 1;
                addList.push_back(toVec2(pos.x + 1, pos.y));
            }
        }
        day++;

        if (addList.empty()) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (v[x][y] == 0) {
                        day = -1;
                        break;
                    }
                }
                if (day == -1) {
                    break;
                }
            }
            // complete
            if (day >= 0) {
                day--;
            }
            break;
        } else {
            for (auto iter = addList.begin(); iter != addList.end(); ++iter) {
                q.push(*iter);
            }
        }
    }

    cout << day;

    return 0;
}
