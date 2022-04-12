#include <iostream>
using namespace std;
int 우유축제()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, m, milk = 0, count = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> m;

		if (m == milk)
		{
			milk++;
			if (milk > 2) milk = 0;
			count++;
		}
	}

	cout << count;

	return 0;
}