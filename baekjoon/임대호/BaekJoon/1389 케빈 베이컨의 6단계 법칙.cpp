//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, m, f1, f2;
//	cin >> n >> m;
//
//	vector<vector<int>> v(n + 1);
//
//	for (int i = 1; i <= n; i++)
//	{
//		v[i] = vector<int>(n + 1, 6);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> f1 >> f2;
//
//		v[f1][f2] = v[f2][f1] = 1;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			for (int k = 1; k <= n; k++)
//			{
//				if (v[j][i] + v[i][k] < v[j][k])
//				{
//					v[j][k] = v[j][i] + v[i][k];
//				}
//			}
//		}
//	}
//
//	int min = 6 * n, sum = 0, min_f = 0;
//	for (int i = n; i >= 1; i--)
//	{
//		sum = 0;
//
//		for (int j = n; j >= 1; j--)
//		{
//			if (i == j) continue;
//
//			sum += v[i][j];
//		}
//
//		if (sum <= min)
//		{
//			min = sum;
//			min_f = i;
//		}
//	}
//
//	cout << min_f;
//
//	return 0;
//}