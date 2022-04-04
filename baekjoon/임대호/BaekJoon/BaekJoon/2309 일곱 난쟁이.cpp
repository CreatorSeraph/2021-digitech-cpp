#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<int> arr(9);
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != j)
			{
				if (sum - arr[i] - arr[j] == 100)
				{
					arr[i] = arr[j] = 0;
					goto EXIT;
				}
			}
		}
	}
	EXIT:

	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << '\n';
	}

	return 0;
}