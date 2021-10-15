#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

#define async_with_stdio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int main()
{
	async_with_stdio;

	int T, k, n;

	cin >> T;
	int persons[15][15] = { 0, };

	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (i == 0)
				persons[i][j] = j + 1;
			else if (j == 0)
				persons[i][j] = 1;
			else if (j == 1)
				persons[i][j] = i + 2;
			else
			{
				persons[i][j] = persons[i][j - 1] + persons[i - 1][j];
			}
		}
	}

	while (T--)
	{
		cin >> k >> n;

		cout << persons[k][n - 1] << '\n';
	}

	return 0;
}