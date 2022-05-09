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
//	int n;
//	cin >> n;
//
//	vector<vector<int>> v(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		v[i].resize(n);
//
//		for (int j = 0; j < n; j++)
//		{
//			cin >> v[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			for (int k = 0; k < n; k++)
//			{
//				if (v[j][i] == 1 && v[i][k]) v[j][k] = 1;
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << v[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//
//
//	return 0;
//}