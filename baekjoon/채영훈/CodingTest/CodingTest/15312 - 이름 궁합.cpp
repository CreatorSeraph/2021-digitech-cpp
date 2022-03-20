#include <iostream>
#include <vector>
#include <list>
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

	vector<int> alpha = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

	string A, B;

	cin >> A >> B;

	int a = A.length(), b = B.length();
	int ab = a + b;

	int idx = ab * (ab + 1) / 2 - 1;
	vector<int> dp(idx);

	for (size_t i = 0; i < a * 2; i += 2)
	{
		dp[i] = alpha[A[i / 2] - 'A'];
		dp[i + 1] = alpha[B[i / 2] - 'A'];
	}

	int temp = 0;

	for (size_t i = ab; i < idx; i++)
	{
		dp[i] = (dp[i - ab] + dp[i - ab + 1]) % 10;
		if (i == ab + temp + (ab - 1) - 1)
		{
			temp += ab;
			ab--;
		}
	}

	cout << dp[idx - 2] << dp[idx - 1] << nl;

	return 0;
}