//#include <iostream>
//#include <map>
//#include <queue>
//#include <set>
//
//using namespace std;
//
//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    long n;
//    int p, q;
//    cin >> n >> p >> q;
//
//    map<long, long> m;
//    m.insert(make_pair(0, 1));
//
//    queue<long> values;
//    set<long> s;
//
//    values.push(n);
//    values.push(n / p);
//    values.push(n / q);
//
//    s.insert(n);
//    s.insert(n / p);
//    s.insert(n / q);
//
//    while (!values.empty()) {
//        auto front = values.front();
//        values.pop();
//
//        if (front / p != 0 && s.find(front / p) == s.end()) {
//            values.push(front / p);
//            s.insert(front / p);
//        }
//        if (front / q != 0 && s.find(front / q) == s.end()) {
//            values.push(front / q);
//            s.insert(front / q);
//        }
//
//    }
//
//    for (auto iter = s.begin(); iter != s.end(); ++iter) {
//        m.insert(make_pair(*iter, m.find(*iter / p)->second + m.find(*iter / q)->second));
//    }
//
//
//    cout << m.find(n)->second;
//
//    return 0;
//}
