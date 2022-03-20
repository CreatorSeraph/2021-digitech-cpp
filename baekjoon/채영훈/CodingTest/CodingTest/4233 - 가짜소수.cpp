#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

using ll = long long;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

ll power(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	if (b == 1) return a % m;

	if (b % 2 == 0) return power(a, b / 2, m) * power(a, b / 2, m) % m;
	else return ((power(a, (b - 1) / 2, m) * power(a, (b - 1) / 2, m)) % m * a % m) % m;
}

bool IsPrime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return n != 1;
}

int main()
{
	async_with_stdio;

	int p, a;

	while (cin >> p >> a, p && a)
	{
		if (IsPrime(p))
		{
			cout << "no" << nl;
			continue;
		}

		if (power(a, p, p) == a) cout << "yes" << nl;
		else cout << "no" << nl;
	}

	return 0;
}