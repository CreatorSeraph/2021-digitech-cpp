#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	int N, M;
	cin >> N >> M;

	unordered_map<string, int> um;

	string temp;
	for (size_t i = 0; i < N + M; i++)
	{
		cin >> temp;
		um[temp]++;
	}

	vector<pair<string, int>> v(um.begin(), um.end());

	stable_sort(v.begin(), v.end(), [](pair<string, int> op1, pair<string, int> op2)->bool 
		{
			return op1.first < op2.first;
		});

	vector<string> names;
	names.reserve(N + M);

	for (auto&& iter : v)
		if (iter.second > 1)
			names.push_back(iter.first);

	cout << names.size() << nl;

	for (auto&& iter : names)
		cout << iter << nl;

	return 0;
}