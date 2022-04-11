#include <iostream>
using namespace std;
int Ä»°Å·ç3¸¶¸®2()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, c, count = 0;

	while (true)
	{
		cin >> a >> b >> c;
		if (cin.fail()) break;

		while (b - a > 1 || c - b > 1)
		{
			if (c - b > b - a)
			{
				a = b++;
			}
			else
			{
				c = b--;
			}

			count++;
		}

		cout << count << '\n';
		count = 0;
	}

	return 0;
}