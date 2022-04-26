//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int t, n, m, temp;
//	cin >> t;
//
//	map<int, int> _m;
//
//	for (int i = 0; i < t; i++)
//	{
//		cin >> n;
//		_m.clear();
//
//		for (int j = 0; j < n; j++)
//		{
//			cin >> temp;
//			_m.insert(make_pair(temp, 0));
//		}
//
//		cin >> m;
//		for (int j = 0; j < m; j++)
//		{
//			cin >> temp;
//
//			if (_m.find(temp) == _m.end())
//				cout << 0;
//			else
//				cout << 1;
//
//			cout << '\n';
//		}
//	}
//
//	return 0;
//}