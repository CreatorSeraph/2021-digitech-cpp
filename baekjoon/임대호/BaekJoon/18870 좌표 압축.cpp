//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//struct Compare {
//    bool operator() (int a, int b) {
//        return a > b;
//    }
//};
//
//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int n;
//    cin >> n;
//
//    vector<int> v(n);
//    priority_queue<int, vector<int>, Compare> q;
//
//    for (int i = 0; i < n; i++) {
//        cin >> v[i];
//
//        q.push(v[i]);
//    }
//
//    int top;
//    map<int, int> m;
//    int value = 0;
//    while (!q.empty()) {
//        top = q.top();
//        q.pop();
//
//        if (m.find(top) != m.end())
//            continue;
//
//        m.insert(make_pair(top, value++));
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << m[v[i]];
//        if (i < n - 1)
//            cout << ' ';
//    }
//
//    return 0;
//}
