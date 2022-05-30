//#include <iostream>
//
//using namespace std;
//
//int Factorial(int n, int sum)
//{
//	if (n <= 0) return sum;
//
//	return Factorial(n - 1, sum * n);
//}
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, k;
//	cin >> n >> k;
//
//	cout << (Factorial(n, 1) / (Factorial(n - k, 1) * Factorial(k, 1)));
//
//	return 0;
//}