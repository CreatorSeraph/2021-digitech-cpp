#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int* dp = nullptr;

int main()
{
	int N;
	cin >> N;

	vector<int> dp(N + 1, 0);
	dp[1] = 1;

	int temp;
	for (int i = 2; i <= N; i++)
	{
		temp = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++)
		{
			temp = min(temp, dp[i - j * j]);
		}
		dp[i] = temp + 1;
	}

	cout << dp[N] << nl;

	return 0;
}