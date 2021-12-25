#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	async_with_stdio;

	long long N, K;
	long long min = 0, max = 0, mid = 0;

	cin >> K >> N;

	vector<int> v(K);

	for (size_t i = 0; i < K; i++)
	{
		cin >> v[i];
		if (max < v[i])	max = v[i];
	}

	while (min <= max)
	{
		mid = (min + max) / 2;
		int count = 0;

		for_each(v.begin(), v.end(), [&count, &mid](int iter)->void
			{
				if (iter >= mid)
				{
					if (mid == 0)
						count += iter / (mid + 1);
					else
						count += iter / mid;
				}
			});

		if (count >= N)
			min = mid + 1;
		else
			max = mid - 1;
	}

	cout << max << nl;

	return 0;
}