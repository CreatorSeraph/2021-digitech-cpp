#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct Vector3 {
public:
    int x, y, z;
};
Vector3 toVec3(int x, int y, int z) {
    Vector3 ret = {x, y, z};
    return ret;
}

int 토마토2() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, h;
    cin >> m >> n >> h;

    vector<vector<vector<int> > > v(m, vector<vector<int> >(h, vector<int>(n)));

    int input;

    queue<Vector3> q;

    for (int y = h - 1; y >= 0; y--) {
        for (int z = 0; z < n; z++) {
            for (int x = 0; x < m; x++) {
                cin >> input;
                v[x][y][z] = input;

                if (input == 1) {
                    q.push(toVec3(x, y, z));
                }
            }
        }
    }

    Vector3 pos;
    list<Vector3> addList;

    int day = 0;
    while (true) {
        addList.clear();

        while (!q.empty()) {
            pos = q.front();
            q.pop();

            if (pos.y > 0 && v[pos.x][pos.y - 1][pos.z] == 0) {
                v[pos.x][pos.y - 1][pos.z] = 1;
                addList.push_back(toVec3(pos.x, pos.y - 1, pos.z));
            }
            if (pos.y < h - 1 && v[pos.x][pos.y + 1][pos.z] == 0) {
                v[pos.x][pos.y + 1][pos.z] = 1;
                addList.push_back(toVec3(pos.x, pos.y + 1, pos.z));
            }
            if (pos.x > 0 && v[pos.x - 1][pos.y][pos.z] == 0) {
                v[pos.x - 1][pos.y][pos.z] = 1;
                addList.push_back(toVec3(pos.x - 1, pos.y, pos.z));
            }
            if (pos.x < m - 1 && v[pos.x + 1][pos.y][pos.z] == 0) {
                v[pos.x + 1][pos.y][pos.z] = 1;
                addList.push_back(toVec3(pos.x + 1, pos.y, pos.z));
            }
            if (pos.z > 0 && v[pos.x][pos.y][pos.z - 1] == 0) {
                v[pos.x][pos.y][pos.z - 1] = 1;
                addList.push_back(toVec3(pos.x, pos.y, pos.z - 1));
            }
            if (pos.z < n - 1 && v[pos.x][pos.y][pos.z + 1] == 0) {
                v[pos.x][pos.y][pos.z + 1] = 1;
                addList.push_back(toVec3(pos.x, pos.y, pos.z + 1));
            }
        }
        day++;

        if (addList.empty()) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < h; y++) {
                    for (int z = 0; z < n; z++) {
                        if (v[x][y][z] == 0) {
                            day = -1;
                            break;
                        }
                    }
                    if (day == -1) {
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
