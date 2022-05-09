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
//	int a, b;
//	cin >> a >> b;
//
//	vector<int> v(b + 1, 1);
//
//	v[0] = v[1] = 0;
//	for (int i = 0; i <= b; i++)
//	{
//		if (v[i] == 0) continue;
//
//		for (int j = i * 2; j <= b; j += i)
//		{
//			v[j] = 0;
//		}
//	}
//
//	for (int i = a; i <= b; i++)
//	{
//		if (v[i] == 1)
//			cout << i << '\n';
//	}
//
//	return 0;
//}