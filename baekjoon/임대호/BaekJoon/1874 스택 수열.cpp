//#include <iostream>
//#include <stack>
//#include <list>
//
//using namespace std;
//int main() {
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//    int n = 0;
//
//    cin >> n;
//    int* arr = new int[n];
//
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    stack<int> s;
//    list<char> str;
//
//    int lastPushedNum = 1;
//    for (int i = 1; i <= n; i++) {
//        while (lastPushedNum <= arr[i - 1]) {
//            s.push(lastPushedNum++);
//            str.push_back('+');
//        }
//
//        if (s.size() == 0) {
//            cout << "NO";
//            return 0;
//        }
//
//        int temp;
//        do {
//            temp = s.top();
//            s.pop();
//            str.push_back('-');
//
//            if (temp == arr[i - 1])
//                break;
//        }
//        while (s.size() > 0);
//
//        if (temp != arr[i - 1]) {
//            cout << "NO";
//            return 0;
//        }
//    }
//
//    while (!str.empty()) {
//        cout << str.front() << '\n';
//        str.pop_front();
//    }
//
//	return 0;
//}
