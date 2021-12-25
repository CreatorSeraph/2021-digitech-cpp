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
	int N;
	cin >> N;

	int count = 0;
	unsigned long long factorial = 24;

	for (size_t i = 4; i < N; i++)
	{
		factorial *= i + 1;

		while (factorial % 10 == 0)
		{
			count++;
			factorial /= 10;
		}

		factorial %= 10000;
	}

	cout << count << nl;

	return 0;
}