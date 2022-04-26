#include <iostream>
using namespace std;
int º°_Âï±â_3()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}