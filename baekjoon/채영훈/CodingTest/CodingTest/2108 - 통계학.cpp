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

	float sum = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	
	cout << round(sum / N) << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	stable_sort(v.begin(), v.end());
	cout << v[(N - 1) / 2] << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	map<int, int> m;
	for_each(v.begin(), v.end(), [&m](int val) { ++m[val]; });
	vector<pair<int, int>> v_pair;
	for_each(m.begin(), m.end(), [&v_pair](auto& p) { v_pair.push_back({ p.first,p.second }); });
	stable_sort(v_pair.begin(), v_pair.end(), [](auto& a, auto& b) { return a.second > b.second; });

	if (m.size() > 1) cout << v_pair[1].first << "\n";
	else cout << v_pair[0].first << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	int min_val = 4001, max_val = -4001;
	for_each(v.begin(), v.end(), [&min_val, &max_val](int val)
		{
			if (min_val > val) min_val = val;
			if (max_val < val) max_val = val;
		});
	
	cout << max_val - min_val << "\n";

	return 0;
}