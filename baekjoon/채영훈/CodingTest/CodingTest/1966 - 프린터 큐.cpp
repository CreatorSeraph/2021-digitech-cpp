#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
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

int main()
{
	async_with_stdio;

	int T;
	cin >> T;

	int N, M;

	for (size_t i = 0; i < T; i++)
	{
		cin >> N >> M;

		if (N == 1)
		{
			cout << 1 << nl;
			continue;
		}

		list<int> l;

		for (size_t j = 0; j < N; j++)
		{
			l.push_back(j);
		}


	}

	return 0;
}