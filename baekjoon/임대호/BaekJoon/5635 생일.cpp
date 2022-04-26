//#include <iostream>
//using namespace std;
//
//struct Human
//{
//public:
//	string name;
//	int y;
//	int m;
//	int d;
//
//	Human() { name = ""; y = 0; m = 0; d = 0; }
//	Human(string name, int y, int m, int d) : name(name), y(y), m(m), d(d) {}
//	~Human() {}
//};
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, m, d, y; string name;
//	Human* min = new Human("temp", 9999, 9999, 9999);
//	Human* max = new Human("temp", 0, 0, 0);
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> name >> d >> m >> y;
//
//		if ((max->y < y) ||
//			(max->y == y && max->m < m) ||
//			(max->y == y && max->m == m && max->d < d))
//		{
//			// max.name = name;
//			// max.y = y;
//			// max.m = m;
//			// max.d = d;
//			max = new Human(name, y, m, d);
//		}
//
//		if ((min->y > y) ||
//			(min->y == y && min->m > m) ||
//			(min->y == y && min->m == m && min->d > d))
//		{
//			// min.name = name;
//			// min.y = y;
//			// min.m = m;
//			// min.d = d;
//			min = new Human(name, y, m, d);
//		}
//	}
//
//	cout << max->name << '\n';
//	cout << min->name;
//
//	return 0;
//}