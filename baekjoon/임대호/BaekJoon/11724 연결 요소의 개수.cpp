// 이거 플로이드 와샬로 풀 수 있을듯

#include <iostream>
#include <list>
#include <map>

using namespace std;

class Point {
public:
    list<Point*> points;
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    int a, b;

    map<int, Point*> points;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        if (points.find(a) == points.end())
            points.insert(make_pair(a, new Point()));

        if (points.find(b) == points.end())
            points.insert(make_pair(b, new Point()));

        points[a]->points.push_back(points[b]);
        points[b]->points.push_back(points[a]);
    }

    while (!points.empty()) {
    }

    return 0;
}
