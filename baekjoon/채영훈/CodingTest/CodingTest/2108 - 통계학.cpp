#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main()
{
	async_with_stdio;

	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	float sum = 0;
	for_each(v.begin(), v.end(), [&sum](int val) {sum += val; });
	cout << round(sum / N) << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	stable_sort(v.begin(), v.end());
	cout << v[(N - 1) / 2] << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	map<int, int> m;
	for_each(v.begin(), v.end(), [&m](int val) {m[val]++; });
	vector<pair<int, int>> v_pair;
	for_each(m.begin(), m.end(), [&v_pair](const pair<int, int> p) { v_pair.push_back({ p.first,p.second }); });
	stable_sort(v_pair.begin(), v_pair.end(), [](const pair<int, int> a, const pair<int, int> b)
		{
			if (a.second > b.second)
				return true;
			else if (a.second == b.second && a.first < b.first)
				return true;
			return false;
		});

	if (v_pair.size() > 1)
		cout << v_pair[1].first << "\n";
	else
		cout << v_pair[0].first << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	int min_val = 4001, max_val = -4001;
	for_each(v.begin(), v.end(), [&min_val, &max_val](int val) {min_val = min(val, min_val); max_val = max(val, max_val); });

	if (min_val != max_val)
		cout << abs(min_val - max_val) << "\n";
	else
		cout << "0\n";

	return 0;
}