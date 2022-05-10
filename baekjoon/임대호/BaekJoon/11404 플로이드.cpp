//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int max_cost = 10000000;
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, m, a1, a2, t;
//	cin >> n >> m;
//
//	vector<vector<int>> v1(n + 1); // ���
//	vector<vector<int>> v2 = v1; // �Ҹ� ���
//
//	for (int i = 1; i <= n; i++)
//	{
//		v1[i] = vector<int>(n + 1);
//		v2[i] = vector<int>(n + 1, max_cost);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a1 >> a2 >> t;
//
//		if (v2[a1][a2] != max_cost && v2[a1][a2] < t)
//			continue;
//
//		v1[a1][a2] = a1;
//		v2[a1][a2] = t;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		v1[i][i] = 0;
//		v2[i][i] = max_cost;
//	}
//
//	int temp;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			for (int k = 1; k <= n; k++)
//			{
//				if (j == i || k == i) continue;
//				if (j == k)
//				{
//					v1[j][k] = 0;
//					v2[j][k] = max_cost;
//					continue;
//				}
//
//				temp = v2[j][i] + v2[i][k];
//
//				if (temp < v2[j][k])
//				{
//					v1[j][k] = v1[i][k];
//
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
//			if (v2[i][j] == max_cost || v1[i][j] == 0) cout << "0 ";
//			else cout << v2[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}