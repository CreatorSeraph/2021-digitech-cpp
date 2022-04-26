#include <iostream>
using namespace std;
int º°_Âï±â_4()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, j = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			cout << ' ';
		}
		for (; j < n; j++)
		{
			cout << '*';
		}

		cout << '\n';
	}

	return 0;
}