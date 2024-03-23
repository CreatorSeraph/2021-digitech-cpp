#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
int 마인크래프트() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, b;

    cin >> n >> m >> b;

    // 존재하는 모든 층 리스트별로 평평하게 만드는 데 드는 시간 구하기
    set<int> floorSet;

    int min = 501;
    int max = 0;
    vector<vector<int> > blocks(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int value = 0;

            cin >> value;

            blocks[i][j] = value;

            if (value < min)
                min = value;
            if (value > max)
                max = value;

        }
    }

    for (int i = min; i <= max; i++)
        floorSet.insert(i);

    map<int, int> floorAndTimeMap;
    int time;
    int tempB;
    int value;
    int blockCount = 0;
    for (auto iter = floorSet.begin(); iter != floorSet.end(); ++iter) {
        time = 0;
        tempB = b;

        value = *iter;
        if (value > 256)
            continue;

        // 얻을 수 있는 블럭 갯수만 미리 구하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (blocks[i][j] < value) {
                    continue;
                } else if (blocks[i][j] > value) {
                    tempB += blocks[i][j] - value;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (blocks[i][j] < value) {
                    blockCount = value - blocks[i][j];
                    tempB -= blockCount;
                    time += blockCount;
                    if (tempB < 0) {
                        goto FAIL;
                    }
                } else if (blocks[i][j] > value) {
                    blockCount = blocks[i][j] - value;
                    // 위에서 미리 블럭 갯수를 더해놨기에 빼지 않는다.
                    // tempB += blockCount;
                    time += blockCount * 2;
                }
            }
        }

        floorAndTimeMap.insert(make_pair(value, time));

        FAIL:;
    }

    pair<int, int> ret = make_pair(-1, -1);
    for (auto iter = floorAndTimeMap.begin(); iter != floorAndTimeMap.end(); ++iter) {
        if (ret.first == -1 && ret.second == -1)
            ret = *iter;
        else {
            if (ret.second > iter->second) {
                ret = *iter;
            } else if (ret.second == iter->second) {
                if (iter->first > ret.first)
                    ret = *iter;
            }
        }
    }

    cout << ret.second << ' ' << ret.first;

    return 0;
}
