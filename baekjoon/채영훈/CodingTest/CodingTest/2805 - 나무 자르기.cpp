#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int M, N;

	cin >> N >> M;

	list<int> l;

	long long val;
	long long min = 0;
	long long mid = 0;
	long long sum = 0;
	long long max = 0;
	long long total = 0;
	for (size_t i = 0; i < N; i++)
	{
		cin >> val;
		if (max < val) max = val;
		l.push_back(val);
		total += val;
	}

	while (min <= max)
	{
		sum = 0;
		mid = (min + max) / 2;
		for_each(l.begin(), l.end(), [&sum, &mid](int iter)->void
			{
				if (iter > mid)
					sum += iter - mid;
			});
		if (sum >= M)
			min = mid + 1;
		else
			max = mid - 1;
	}

	cout << max << nl;

	return 0;
}