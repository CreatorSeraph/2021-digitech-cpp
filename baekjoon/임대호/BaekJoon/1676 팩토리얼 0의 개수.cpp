//#include <iostream>
//#include <vector>
//
//#define ull unsigned long long
//
//using namespace std;
//
//ull Factorial(int n1) {
//    vector<ull> v;
//
//    v.resize(n1);
//
//    if (n1 <= 1)
//        return 1;
//
//    v[0] = 1;
//    for (int i = 1; i < n1; i++) {
//        v[i] = v[i - 1] * (i + 1);
//    }
//
//    return v.back();
//}
//
//int main() {
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//    int n;
//    cin >> n;
//
//    ull factorial = Factorial(n);
//    cout << factorial << '\n';
//    string str = to_string(factorial);
//
//    int ret = 0;
//    while (true) {
//        char c = str.back();
//        str.pop_back();
//
//        if (c == '0') {
//            ret++;
//        } else {
//            break;
//        }
//    }
//
//    cout << ret;
//
//	return 0;
//}