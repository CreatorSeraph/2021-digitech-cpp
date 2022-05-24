//#include <iostream>
//using namespace std;
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//
//	for (int i = -n + 1; i < n; i++)
//	{
//		int j = 0;
//		for (; j < abs(i); j++)
//		{
//			cout << ' ';
//		}
//		for (j = 0; j < ((n - 1) - abs(i)) *2 + 1; j++)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}