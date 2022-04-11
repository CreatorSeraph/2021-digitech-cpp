#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ¼öÃ£±â()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<int> v1(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}

	cin >> m;
	vector<int> v2(m);

	for (int i = 0; i < m; i++)
	{
		cin >> v2[i];
	}

	sort(v1.begin(), v1.end());

	int start, pivot, value;

	for (int i = 0; i < m; i++)
	{
		start = 0;
		pivot = n / 2;
		value = 0;
		do
		{
			if (v1[pivot] > v2[i])
			{
				pivot = (start + pivot) / 2;
			}
			else if (v1[pivot] < v2[i])
			{
				start = pivot;
				pivot = (start + n) / 2;
			}

			if (v1[pivot] == v2[i])
			{
				value = 1;
				break;
			}

		} while (pivot != start);

		cout << value << '\n';
	}

	return 0;
}