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

	for (size_t i = 0; i < T; i++)
	{
		cin >> v[0] >> v[1] >> v[2];

		sort(v.begin(), v.end());

	}

	return 0;
}
