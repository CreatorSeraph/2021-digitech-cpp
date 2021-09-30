#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';

int main()
{
	async_with_stdio;

	int K, N; cin >> K;

	stack<int> s;

	for (int i = 0; i < K; i++)
	{
		cin >> N;

		if (N == 0) s.pop();
		else s.push(N);
	}

	int sum = 0;

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum << nl;

	return 0;
}