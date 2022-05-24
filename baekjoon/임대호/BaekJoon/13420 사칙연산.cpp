//#include <iostream>
//using namespace std;
//
//void Function(bool correct)
//{
//	if (correct) cout << "correct";
//	else cout << "wrong answer";
//
//	cout << '\n';
//}
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n; long long a, b, result;
//	char c, temp;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a;
//		cin >> c;
//		cin >> b;
//		cin >> temp;
//		cin >> result;
//
//		if (c == '+')
//		{
//			Function(a + b == result);
//		}
//		else if (c == '-')
//		{
//			Function(a - b == result);
//		}
//		else if (c == '*')
//		{
//			Function(a * b == result);
//		}
//		else if (c == '/')
//		{
//			Function(a / b == result);
//		}
//	}
//
//	return 0;
//}