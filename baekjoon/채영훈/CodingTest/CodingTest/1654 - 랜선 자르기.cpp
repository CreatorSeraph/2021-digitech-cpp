#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

bool check(const vector<int>& v, int mid, int need)
{
	int count = 0;
	for (auto&& iter : v)
	{
		count += iter / mid;
	}
	return count >= need;
}

int main()
{
	async_with_stdio;

	int K, N;
	long long start = 0, end = 0, result = 0;
	cin >> K >> N;

	vector<int> v(K);
	for (size_t i = 0; i < K; i++)
	{
		cin >> v[i];
		if (end < v[i]) end = v[i];
	}

	if (check(v, end, N))
	{
		cout << end << nl;
		return 0;
	}

	while (start < end)
	{
		long long mid = (start + end) / 2;

		if (check(v, mid, N))
		{
			start = mid + 1;
			result = mid;
		}
		else
			end = mid - 1;
	}

	cout << result << nl;

	return 0;
}