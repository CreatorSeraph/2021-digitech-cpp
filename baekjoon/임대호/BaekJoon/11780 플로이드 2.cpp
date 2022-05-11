//#include <iostream>
//#include <vector>
//#include <list>
//
//using namespace std;
//
//long long max_cost = 100000 * 100000;
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, m, c1, c2; long long c;
//	cin >> n >> m;
//
//	vector<vector<int>> v1(n + 1);
//	vector<vector<long long>> v2(n + 1);
//
//	for (int i = 1; i <= n; i++)
//	{
//		v1[i] = vector<int>(n + 1);
//		v2[i] = vector<long long>(n + 1, max_cost);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> c1 >> c2 >> c;
//
//		if (v1[c1][c2] != 0 && v2[c1][c2] <= c) continue;
//
//		v1[c1][c2] = c1;
//		v2[c1][c2] = c;
//	}
//
//	long long temp;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			for (int k = 1; k <= n; k++)
//			{
//				if (j == k)
//				{
//					v1[j][k] = 0;
//					v2[j][k] = max_cost;
//					continue;
//				}
//
//				temp = v2[j][i] + v2[i][k];
//				if (temp < v2[j][k])
//				{
//					v1[j][k] = v1[i][k];
//					v2[j][k] = temp;
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (v2[i][j] >= max_cost) cout << "0 ";
//			else cout << v2[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//
//	int path;
//	list<int> pathes;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (v2[i][j] >= max_cost) cout << "0\n";
//			else
//			{
//				if (v1[i][j] != i)
//				{
//					path = v1[i][j];
//					pathes.push_front(path);
//
//					while (i != v1[i][path])
//					{
//						path = v1[i][path];
//						pathes.push_front(path);
//					}
//				}
//
//				cout << pathes.size() + 2 << ' ';
//				cout << i << ' ';
//				for (auto iter = pathes.begin(); iter != pathes.end(); ++iter)
//					cout << (*iter) << ' ';
//
//				cout << j << '\n';
//				pathes.clear();
//			}
//		}
//	}
//
//	return 0;
//}