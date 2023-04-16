#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> path;
vector<vector<int>> cost;

void FloydWalshall(int size)
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			for (int k = 1; k <= size; k++)
			{
				if (cost[j][k] > cost[j][i] + cost[i][k])
				{
					path[j][k] = path[i][k];

					cost[j][k] = cost[j][i] + cost[i][k];
				}
			}
		}
	}
}

int 비밀모임()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, k;
	int a, b, c;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> n >> m;

		path = vector<vector<int>>(n + 1, vector<int>(n + 1));
		cost = vector<vector<int>>(n + 1, vector<int>(n + 1));

		for (int j = 0; j < m; j++)
		{
			cin >> a >> b >> c;

			path[a][b] = a;
			cost[a][b] = c;
		}

		FloydWalshall(n);

		cin >> k;
		int* arr = new int[k];
		for (int j = 0; j < k; j++)
			cin >> arr[j];

		int* sum = new int[n];
		int index;
		int min = 100001;

		for (int j = n; j >= 1; j--)
		{
			for (int l = 0; l < k; l++)
			{
				sum[j] += cost[arr[l]][j];
			}

			if (sum[j] < min)
			{
				min = sum[j];
				index = j;
			}
		}

		cout << index;
	}

	return 0;
}