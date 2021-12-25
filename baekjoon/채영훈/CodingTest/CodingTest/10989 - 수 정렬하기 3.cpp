#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> v(10001);

	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		++v[temp];
	}

	for (int i = 1; i <= 10000; ++i)
		for (int j = 0; j < v[i]; ++j)
			cout << i << "\n";

	return 0;
}