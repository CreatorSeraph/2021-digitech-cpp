#include <iostream>
#include <vector>

using namespace std;

const long long max_cost = 10000000000;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, c1, c2, c;
	cin >> n >> m;

	vector<vector<int>> v1(n + 1);
	vector<vector<int>> v2(n + 1);

	for (int i = 1; i <= n; i++)
	{
		v1[i] = vector<int>(n + 1);
		v2[i] = vector<int>(n + 1, max_cost);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> c1 >> c2 >> c;

		v1[c1][c2] = c1;
		v2[c1][c2] = c;
	}

	int temp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (j == k)
				{
					v1[j][k] = 0;
					v2[j][k] = max_cost;
					continue;
				}

				temp = v2[j][i] + v2[i][k];
				if (temp < v2[j][k])
				{
					v1[j][k] = v1[i][k];
					v2[j][k] = temp;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (v2[i][j] >= max_cost) cout << "0 ";
			else cout << v2[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}