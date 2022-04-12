#include <iostream>
#include <math.h>

using namespace std;
int arr[10][4] =
{
	{1, 1, 1, 1},
	{6, 2, 4, 8},
	{1, 3, 9, 7},
	{6, 4, 6, 4},
	{5, 5, 5,5 },
	{6, 6, 6, 6},
	{1, 7, 9, 3},
	{6, 8, 4, 2},
	{1, 9, 1, 9}
};

int 분산처리()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, a, b;
	int result = 10;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		if (a % 10 == 0)
			result = 10;

		else if (b == 1)
			result = a % 10;

		else
			for (int j = 0; j < 4; j++)
			{
				if (b % 4 == j)
				{
					result = arr[(a % 10) - 1][j];
					break;
				}
			}

		cout << result << '\n';
	}

	return 0;
}