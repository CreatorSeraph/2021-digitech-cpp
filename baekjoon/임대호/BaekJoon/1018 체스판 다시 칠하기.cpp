#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> vec(n);

	for (int i = 0; i < n; i++)
	{
		vec[i].resize(m);

		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
		}
	}

	int count, max = 0, ind_x = 0, ind_y = 0;
	bool once = true;
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			count = 1;

			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if (l > j && vec[k][l] != vec[k][l - 1])
					{
						count++;

						if (count == 64)
						{
							cout << 0;
							return 0;
						}

						if (count > max)
						{
							max = count;
							ind_x = l;
							ind_y = k;
						}
					}
					else if (k > i && vec[k][l] != vec[k - 1][l])
					{
						if (once)
						{
							count++;

							if (count == 64)
							{
								cout << 0;
								return 0;
							}

							if (count > max)
							{
								max = count;
								ind_x = l;
								ind_y = k;
							}
						}
					}
					once = !once;
				}
			}
		}
	}

	if (ind_x - 7 < 0) ind_x = 7;
	if (ind_y - 7 < 0) ind_y = 7;

	vector<vector<char>> _vec = vec;

	_vec[ind_y][ind_x] = _vec[ind_y][ind_x] == 'B' ? 'W' : 'B';

	int result_1 = 0, result_2 = 0;
	for (int y = ind_y; y >= ind_y - 7; y--)
	{
		for (int x = ind_x; x >= ind_x - 7; x--)
		{
			if (x < ind_x)
			{
				if (vec[y][x] == vec[y][x + 1])
				{
					result_1++;

					vec[y][x] = (vec[y][x + 1] == 'B' ? 'W' : 'B');
				}

				if (_vec[y][x] == _vec[y][x + 1])
				{
					result_2++;

					_vec[y][x] = (_vec[y][x + 1] == 'B' ? 'W' : 'B');
				}
			}
			else if (y < ind_y)
			{
				if (vec[y][x] == vec[y + 1][x])
				{
					result_1++;

					vec[y][x] = (vec[y + 1][x] == 'B' ? 'W' : 'B');
				}

				if (_vec[y][x] == _vec[y + 1][x])
				{
					result_2++;

					_vec[y][x] = (_vec[y + 1][x] == 'B' ? 'W' : 'B');
				}
			}
		}
	}

	cout << (result_1 < result_2 ? result_1 : result_2);

	return 0;
}