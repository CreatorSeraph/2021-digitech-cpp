#include <iostream>
#include <cmath>

using namespace std;

long long power(int a, int b, int m)
{
	if (b == 0) return 1;
	if (b == 1) return a % m;

	if (b % 2 == 0) return power(a, b / 2, m) * power(a, b / 2, m) % m;
	else return ((power(a, (b - 1) / 2, m) * power(a, (b - 1) / 2, m)) % m * a % m) % m;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	cout << power(A, B, C);

	return 0;
}