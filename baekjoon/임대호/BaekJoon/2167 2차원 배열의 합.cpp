//#include <iostream>
//#include <vector>
//
//using namespace std;
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, m;
//	cin >> n >> m;
//
//	vector<vector<int>> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		v[i] = vector<int>(m);
//
//		for (int j = 0; j < m; j++)
//		{
//			cin >> v[i][j];
//		}
//	}
//
//	int c, x1, y1, x2, y2, sum;
//	cin >> c;
//
//	for (int i = 0; i < c; i++)
//	{
//		cin >> y1 >> x1 >> y2 >> x2;
//
//		sum = 0;
//		for (int y = y1 - 1; y < y2; y++)
//		{
//			for (int x = x1 - 1; x < x2; x++)
//			{
//				sum += v[y][x];
//			}
//		}
//
//		cout << sum << '\n';
//	}
//
//	return 0;
//}