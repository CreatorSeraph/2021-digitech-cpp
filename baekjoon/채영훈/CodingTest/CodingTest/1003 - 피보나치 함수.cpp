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
	int T,N;
	cin >> T;

	vector<pair<int, int>> dp(41, pair<int, int>(0, 0));

	for (size_t i = 0; i < T; i++)
	{
		cin >> N;

		dp[0].first = 0;
		dp[0].second = 1;
		dp[1].first = 1;
		dp[1].second = 0;
		dp[2].first = 1;
		dp[2].second = 1;

		for (size_t i = 3; i <= N; i++)
		{
			dp[i].first = dp[i - 1].first + dp[i - 2].first;
			dp[i].second = dp[i - 1].second + dp[i - 2].second;
		}

		cout << dp[N].second << " " << dp[N].first << nl;
	}

	return 0;
}