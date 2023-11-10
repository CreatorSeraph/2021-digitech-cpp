//#include <iostream>
//#include <list>
//#include <utility>
//
//using namespace std;
//
//int main() {
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//    int count, n, m;
//
//    cin >> count;
//
//    for (int i = 0; i < count; i++) {
//        cin >> n >> m;
//
//        int ret = 0;
//        list<pair<int, int> > l;
//        for (int j = 0; j < n; j++) {
//            int temp;
//            cin >> temp;
//
//            l.push_back(make_pair(j, temp));
//        }
//
//        while (!l.empty()) {
//            int max = 0;
//            pair<int, int> elem;
//            auto f = l.front();
//            for (auto iter : l) {
//                int item2 = get<1>(iter);
//
//                if (item2 > max) {
//                    max = item2;
//                    elem = iter;
//                }
//            }
//
//            l.pop_front();
//            if (get<1>(f) == max) {
//                ret++;
//
//                if (get<0>(f) == m) {
//                    cout << ret << '\n';
//                    break;
//                }
//            } else {
//                l.push_back(f);
//            }
//        }
//    }
//
//
//	return 0;
//}