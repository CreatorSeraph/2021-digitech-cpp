#include <iostream>
using namespace std;
int º°_Âï±â_6()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = n; i >= 0; i--)
	{
		for (int j = n; j > i; j--)
		{
			cout << ' ';
		}

		for (int j = 0; j < i * 2 - 1; j++)
		{
			cout << '*';
		}

		cout << '\n';
	}

	return 0;
}