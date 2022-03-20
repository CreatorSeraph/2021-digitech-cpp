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

	vector<int> v(3);

	unsigned long long sum = 0, div = 0;

	for (size_t i = 0; i < T; i++)
	{
		cin >> v[0] >> v[1] >> v[2];

		sort(v.begin(), v.end());

		sum += v[0] + v[1] + v[2];

		if (sum % 2 == 0)
		{
			sum -= 2;
			div = sum / 2;
		}
		else
		{
			sum -= 3;
			div = sum / 2;
		}

		if (div % 2 == 0) cout << "R" << nl;
		else cout << "B" << nl;
	}

	return 0;
}
