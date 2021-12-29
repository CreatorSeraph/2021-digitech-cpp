#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	async_with_stdio;

	int T;
	cin >> T;

	int x, y, z, even;

	for (size_t i = 0; i < T; i++)
	{
		cin >> x >> y >> z;

		even = 0;

		if (x % 2 == 0) even++;
		if (y % 2 == 0) even++;
		if (z % 2 == 0) even++;

		if (even >= 2) cout << "R" << nl;
		else cout << "B" << nl;
	}

	return 0;
}