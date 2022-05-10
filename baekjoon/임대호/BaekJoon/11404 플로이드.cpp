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

	vector<vector<int>> v1(n + 1); // 경로
	vector<vector<int>> v2 = v1; // 소모 비용

	for (int i = 1; i <= n; i++)
	{
		v1[i] = vector<int>(n + 1);
		v2[i] = vector<int>(n + 1, 100001);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a1 >> a2 >> t;

		if (v2[a1][a2] != 100001 && v2[a1][a2] < t)
			continue;

		v1[a1][a2] = a1;
		v2[a1][a2] = t;
	}

	int temp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (j == i || k == i) continue;

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
			if (i == j) cout << "0 ";
			else cout << v2[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}