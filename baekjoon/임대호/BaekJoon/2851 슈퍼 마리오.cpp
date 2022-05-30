//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, sum = 0;
//	while (true)
//	{
//		cin >> n;
//
//		if (cin.eof()) break;
//
//		if (abs(100 - (sum + n)) <= abs(100 - sum))
//			sum += n;
//		else
//		{
//			cout << sum;
//			return 0;
//		}
//	}
//
//	cout << sum;
//
//	return 0;
//}