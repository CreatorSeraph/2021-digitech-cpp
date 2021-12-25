#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

void Eratos(vector<bool>& eratos, vector<int>& prime, int index, int min, int max)
{
	bool isFirst = true;
	for (size_t i = index; i < eratos.size(); i += index)
	{
		if (eratos[i]) continue;

		eratos[i] = true;

		if (!isFirst) continue;
		isFirst = false;

		if (min > i || i > max) continue;

		prime.push_back(i);
	}
}

int main()
{
	async_with_stdio;

	int M, N;
	cin >> M >> N;

	int maxEraseValue = sqrt(N) + 1;

	vector<bool> eratos(N + 1, false);
	vector<int> prime;
	prime.reserve(1000000);

	for (size_t i = 2; i <= N; i++)
	{
		if (i < maxEraseValue)
			Eratos(eratos, prime, i, M, N);
		else if (!eratos[i] && M <= i && i <= N)
			prime.push_back(i);
	}

	for (auto&& iter : prime)
		cout << iter << nl;

	return 0;
}