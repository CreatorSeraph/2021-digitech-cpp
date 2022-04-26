#include <iostream>
using namespace std;
int º°_Âï±â_5()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
			cout << ' ';

		for (int j = 0; j < i * 2 + 1; j++)
			cout << '*';

		cout << '\n';
	}

	return 0;
}