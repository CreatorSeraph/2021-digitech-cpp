// - 버려진 체스판입니다 -

#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int 체스판다시칠하기()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int x, y, re_coloring_count = 0, c_re_coloring_count = 0;

	cin >> y >> x;

	vector<vector<char>> color(x);
	vector<vector<char>> c_color(x);

	char c;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> c;
			color[i].push_back(c);
			c_color[i].push_back(c);

			if (i == 0 && j == 0)
			{
				c_color[0][0] = (c_color[0][0] == 'W' ? 'B' : 'W');
				c_re_coloring_count++;
			}

			if (j > 0)
			{
				if (c == color[i][j - 1])
				{
					re_coloring_count++;
					color[i][j] = (color[i][j] == 'W' ? 'B' : 'W');
				}

				if (c == c_color[i][j - 1])
				{
					c_re_coloring_count++;
					c_color[i][j] = (c_color[i][j] == 'W' ? 'B' : 'W');
				}
			}
		}
	}

	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
		{
			if (i > 0)
			{
				if (color[i][j] == color[i - 1][j])
				{
					re_coloring_count++;
					color[i][j] = (color[i][j] == 'W' ? 'B' : 'W');
				}
				if (c_color[i][j] == c_color[i - 1][j])
				{
					c_re_coloring_count++;
					c_color[i][j] = (c_color[i][j] == 'W' ? 'B' : 'W');
				}
			}
		}
	}
	 
	cout << (re_coloring_count < c_re_coloring_count ? re_coloring_count : c_re_coloring_count);

	return 0;
}