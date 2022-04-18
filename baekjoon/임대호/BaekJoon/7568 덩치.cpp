#include <iostream>
#include <vector>

using namespace std;

struct XY
{
public:
	XY() {}
	XY(int x, int y) : x(x), y(y) {}

	int x;
	int y;
	int value = 1;
};

int µ¢Ä¡()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<XY> v(n);

	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;

		v[i] = XY(x, y);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				if (v[i].x > v[j].x)
				{
					if (v[i].y > v[j].y)
						v[j].value++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << v[i].value << ' ';

	return 0;
}