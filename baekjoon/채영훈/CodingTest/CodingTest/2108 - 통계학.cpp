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
	vector<int> appear(8001);

	double sum = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		sum += v[i];
		++appear[v[i] + 4000];
	}

	cout << round(sum / N) << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	stable_sort(v.begin(), v.end());
	cout << v[(N - 1) / 2] << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	//   idx  appear
	pair<int, int> first = { 0,0 };
	pair<int, int> second = { 0,0 };

	for (int i = 0; i < appear.size(); i++)
	{
		if (first.second < appear[i])
		{
			second = first;
			first = { i - 4000,appear[i] };
		}
		else if (second.second < appear[i] && appear[i] <= first.second)
		{
			second = { i - 4000,appear[i] };
		}
	}

	if (second.second != 0)
		cout << second.first << "\n";
	else
		cout << first.first << "\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	cout << v[v.size() - 1] - v[0] << "\n";

	return 0;
}