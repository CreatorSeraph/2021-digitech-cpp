#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	int N, M, down = 0, right = 0, x = 0, y = 0;
	cin >> N >> M;

	down = N - 8, right = M - 8;

	vector<string> chess(N);
	vector<int> W, B;

	W.resize((down + 1) * (right + 1), 0);
	B.resize((down + 1) * (right + 1), 0);

	for (size_t i = 0; i < N; i++)
		cin >> chess[i];

	// x : 0 -> right
	// y : 0 -> down

	// i : y -> 7 + y ( 8 )
	int i = y, j = x;
	for (; i < 8 + y; i++)
	{
		//cout << "\n" << "\n";
		//cout << "\t\ti loop : " << i << "\t" << y << "\n";
		// j : x -> 7 + x ( 8 )
		x = 0;
		for (j = x; j < 8 + x; j++) // 
		{
			if ((i + 1) % 2 == 1)// i = ¦ ( 0 )
			{
				if ((j + 1) % 2 == 1) // ¦
				{
					if (chess[i][j] != 'W')
						++W[y * (right + 1) + x];
					if (chess[i][j] != 'B')
						++B[y * (right + 1) + x];
				}
				else
				{
					if (chess[i][j] != 'W')
						++B[y * (right + 1) + x];
					if (chess[i][j] != 'B')
						++W[y * (right + 1) + x];
				}
			}
			if ((i + 1) % 2 == 0)// i = Ȧ
			{
				if (j % 2 == 1) // Ȧ
				{
					if (chess[i][j] != 'W')
						++W[y * (right + 1) + x];
					if (chess[i][j] != 'B')
						++B[y * (right + 1) + x];
				}
				else
				{
					if (chess[i][j] != 'W')
						++B[y * (right + 1) + x];
					if (chess[i][j] != 'B')
						++W[y * (right + 1) + x];
				}
			}

			//cout << "j loop : " << j << "\t" << x << "\n";
			if (x < right && j == 7 + x)
				j = x, ++x;
		}
		// ����� j�� right��ŭ ���������� �̵����Ŀ� ����, �׷��� y�� ���ؼ� ������
		if (y < down)
			if (i == 7 + y)
				i = y, ++y;
	}

	int min_val = 10000000000;

	for (size_t y = 0; y < down + 1; y++)
		for (size_t x = 0; x < right + 1; x++)
		{
			int temp = min(W[y * (right + 1) + x], B[y * (right + 1) + x]);
			if (min_val > temp) min_val = temp;
		}

	cout << min_val << endl;

	return 0;
}