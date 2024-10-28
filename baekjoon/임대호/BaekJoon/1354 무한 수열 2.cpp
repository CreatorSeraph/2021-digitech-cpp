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
//    int p, q, x, y;
//    cin >> n >> p >> q >> x >> y;
//
//    map<long, long> m;
//    m.insert(make_pair(0, 1));
//
//    queue<long> values;
//    set<long> s;
//
//    values.push(n);
//    if (n / p - x > 0) {
//        values.push(n / p - x);
//        s.insert(n / p - x);
//    }
//    if (n / q - y > 0) {
//        values.push(n / q - y);
//        s.insert(n / q - y);
//    }
//
//    s.insert(n);
//
//    long v1;
//    long v2;
//    long front;
//
//    while (!values.empty()) {
//        front = values.front();
//        values.pop();
//
//        v1 = front / p - x;
//        if (v1 > 0 && s.find(v1) == s.end()) {
//            values.push(v1);
//            s.insert(v1);
//        }
//
//        v2 = front / q - y;
//        if (v2 > 0 && s.find(v2) == s.end()) {
//            values.push(v2);
//            s.insert(v2);
//        }
//
//        if (v1 <= 0 && v2 <= 0) {
//            while (!values.empty())
//                values.pop();
//            break;
//        }
//    }
//
//    set<long>::iterator iter;
//    map<long, long>::iterator find1;
//    map<long, long>::iterator find2;
//
////    for (iter = s.begin(); iter != s.end(); ++iter) {
//    while (!s.empty()) {
//        iter = s.begin();
//
//        v1 = *iter / p - x;
//        v2 = *iter / q - y;
//
//        if (v1 < 0)
//            v1 = 0;
//        if (v2 < 0)
//            v2 = 0;
//
//        find1 = m.find(v1);
//        find2 = m.find(v2);
//
//        m.insert(make_pair(*iter, find1->second + find2->second));
//
//        s.erase(iter);
//    }
//
//    cout << m.find(n)->second;
//
//    return 0;
//}
