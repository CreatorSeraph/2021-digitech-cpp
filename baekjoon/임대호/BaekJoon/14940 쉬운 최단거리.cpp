#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Pos {
public:
    Pos(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
    int x; int y;
    int dist;
};
int n, m;

void FloodFill(int startX, int startY, int dist, vector<vector<int> >& v, vector<vector<int> >& map, vector<vector<bool> >& visited) {
    queue<Pos*> poses;
    poses.push(new Pos(startX, startY, dist));

    while (!poses.empty()) {
        Pos* pos = poses.front();
        poses.pop();

        if (pos->x < 0 || pos->y < 0 || pos->x >= n || pos->y >= m) {
        } else if (v[pos->x][pos->y] == 0) {
        } else if (visited[pos->x][pos->y]) {
        } else {
            if (dist < map[pos->x][pos->y]) {
                map[pos->x][pos->y] = pos->dist;
            }

            visited[pos->x][pos->y] = true;

            poses.push(new Pos(pos->x - 1, pos->y, pos->dist + 1));
            poses.push(new Pos(pos->x + 1, pos->y, pos->dist + 1));
            poses.push(new Pos(pos->x, pos->y + 1, pos->dist + 1));
            poses.push(new Pos(pos->x, pos->y - 1, pos->dist + 1));
        }

        delete pos;
    }

}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

    cin >> n >> m;

    vector<vector<int> > v(n, vector<int>(m, 10000));
    vector<vector<int> > map(n, vector<int>(m, 10000));
    vector<vector<bool> > visited(n, vector<bool>(m, false));

    int targetX, targetY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                targetX = i;
                targetY = j;

                map[i][j] = 0;
            } else if (v[i][j] == 0) {
                map[i][j] = 10001;
            }
        }
    }

    FloodFill(targetX, targetY, 0, v, map, visited);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dist = map[i][j];
            if (dist == 10000)
                cout << -1 << ' ';
            else if (dist == 10001)
                cout << 0 << ' ';
            else
                cout << dist << ' ';
        }

        cout << '\n';
    }

	return 0;
}