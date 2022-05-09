#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, a1, a2, t;
	cin >> n >> m;

	vector<vector<int>> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		v[i] = vector<int>(n + 1, -1);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a1 >> a2 >> t;

		v[a1][a2] = v[a2][a1] = t;
	}

	int temp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (j == k) continue;

				temp = v[j][i] + v[i][k];

				if (temp < v[j][k] || (v[j][i] == -1 || v[i][k] == -1))
				{
					v[j][k] = temp;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) cout << '- ';
			else cout << v[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}