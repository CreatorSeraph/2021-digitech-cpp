//#include <iostream>
//#include <vector>
//
//const char solved_arr[8][8] =
//{
//	{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
//	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
//	{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
//	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
//	{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
//	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
//	{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
//	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
//};
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
//	vector<vector<char>> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		v[i].resize(m);
//
//		for (int j = 0; j < m; j++)
//		{
//			cin >> v[i][j];
//		}
//	}
//
//	int min_1 = 64, min_2 = 64, count_1 = 0, count_2 = 0;
//
//	for (int i = 0; i < (n - 8 + 1); i++)
//	{
//		for (int j = 0; j < (m - 8 + 1); j++)
//		{
//			for (int y = i; y < 8 + i; y++)
//			{
//				for (int x = j; x < 8 + j; x++)
//				{
//					if (v[y][x] != solved_arr[y - i][x - j])
//						count_1++;
//					else
//						count_2++;
//				}
//			}
//
//			if (count_1 < min_1)
//				min_1 = count_1;
//			if (count_2 < min_2)
//				min_2 = count_2;
//
//			count_1 = count_2 = 0;
//		}
//	}
//
//	cout << (min_1 < min_2 ? min_1 : min_2);
//
//	return 0;
//}