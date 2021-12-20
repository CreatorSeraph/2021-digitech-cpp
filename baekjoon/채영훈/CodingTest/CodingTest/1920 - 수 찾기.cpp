#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int N, M;

	cin >> N;

	vector<int> A(N);

	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	cin >> M;

	vector<int> v(M);

	int val;
	for (size_t i = 0; i < M; i++)
	{
		cin >> val;

		if (val < A.front() || A.back() < val)
		{
			cout << 0 << nl;
			continue;
		}

		int left = 0, right = N - 1;

		while (true)
		{
			if (A[(left + right) / 2] == val) { cout << 1 << nl; break; }
			else if (A[(left + right) / 2] > val) right = ((left + right) / 2) - 1;
			else if (A[(left + right) / 2] < val) left = ((left + right) / 2) + 1;

			if (left > right) { cout << 0 << nl; break; }
		}
	}

	return 0;
}