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

int dp[10000001];

int main()
{
	async_with_stdio;

	int N;
	cin >> N;

	dp[1] = 0;
	for (size_t i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		cout << i << tab << i - 1 << tab;
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		cout << nl;
	}

	cout << dp[N] << nl;

	return 0;
}