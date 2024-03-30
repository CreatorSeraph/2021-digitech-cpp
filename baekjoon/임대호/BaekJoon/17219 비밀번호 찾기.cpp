#include <iostream>
#include <map>

using namespace std;
int 비밀번호찾기() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string key, value;
    map<string, string> dict;
    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        dict.insert(make_pair(key, value));
    }

    string target;
    for (int i = 0; i < m; i++) {
        cin >> target;
        cout << dict[target] << '\n';
    }

    return 0;
}
