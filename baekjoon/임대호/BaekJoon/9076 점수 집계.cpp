#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int 접수집계()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(5);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> vec[j];
		}

		sort(vec.begin(), vec.end());
		if (vec[3] - vec[1] >= 4) cout << "KIN" << '\n';
		else cout << vec[1] + vec[2] + vec[3] << '\n';
	}

	return 0;
}