#include <iostream>
#include <set>

using namespace std;
int 집합도날먹나이스() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

    set<int> s20;
    for (int i = 1; i <= 20; i++)
        s20.insert(i);

    set<int> s;

    int n;
    cin >> n;

    int v;
    string command;
    for (int i = 0; i < n; i++) {
        cin >> command;

        if (command == "add") {
            cin >> v;
            s.insert(v);
        } else if (command == "remove") {
            cin >> v;
            s.erase(v);
        } else if (command == "check") {
            cin >> v;
            if (s.find(v) != s.end())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (command == "toggle") {
            cin >> v;
            size_t ret = s.erase(v);
            if (ret == 0)
                s.insert(v);
        } else if (command == "all") {
            s = s20;
        } else if (command == "empty") {
            s.clear();
        }
    }

	return 0;
}