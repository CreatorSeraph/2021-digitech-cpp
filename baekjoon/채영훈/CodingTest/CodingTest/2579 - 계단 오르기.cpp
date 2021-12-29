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

	int N;
	cin >> N;

	vector<int> dp(N + 1, 0);
	vector<int> v(N + 1, 0);

	for (int i = 1; i < N + 1; i++)
		cin >> v[i];

	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	dp[3] = max(v[1], v[2]) + v[3];

	for (size_t i = 4; i < N + 1; i++)
		dp[i] = max(v[i] + dp[i - 2], v[i] + v[i - 1] + dp[i - 3]);

	cout << dp[N] << nl;

	return 0;
}