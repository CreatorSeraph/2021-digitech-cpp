#include <iostream>
#include <vector>

using namespace std;

int 소수찾기()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	const int count = 1000;
	vector<int> arr(count + 1, 1);
	arr[0] = 0;
	arr[1] = 0;
	
	int n, result = 0;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 2; i <= count; i++)
	{
		if (arr[i] == 0) continue;

		for (int j = 2 * i; j <= count; j += i)
		{
			arr[j] = 0;
		}
	}

	for (auto i : v)
		if (arr[i] != 0) result++;

	cout << result;

	return 0;
}