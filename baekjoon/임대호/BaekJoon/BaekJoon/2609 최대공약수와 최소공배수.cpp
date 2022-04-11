#include <iostream>

using namespace std;

int Euclid_Hoze(int big, int small)
{
	int temp = big % small;
	if (temp == 0) return small;
	return Euclid_Hoze(small, temp);
}

int 최대공약수와최소공배수()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, result_1, result_2;

	cin >> a >> b;

	if (a > b)
	{
		result_1 = Euclid_Hoze(a, b);
	}
	else
	{
		result_1 = Euclid_Hoze(b, a);
	}

	cout << result_1 << '\n';

	int _a = a, _b = b;
	if (_a != _b)
		while (true)
		{
			if (_a < _b)
			{
				_a += a;
			}
			else
			{
				_b += b;
			}

			if (_a == _b)
			{
				break;
			}
		}

	cout << _a << '\n';

	return 0;
}