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

using ll = long long;
using ul = unsigned long;
using mc_cp = map<char, char*>;
using mc_pc_c = map<char, pair<char, char>>;
using pi_s = pair<int, string>;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

bool Compare(const pi_s& a, const pi_s& b)
{
	return a.first < b.first;
}

int main()
{
	async_with_stdio;

	int N, age;
	string name;
	cin >> N;

	vector<pi_s> v;
	v.reserve(N);

	for (size_t i = 0; i < N; i++)
	{
		cin >> age >> name;
		v.push_back({ age,name });
	}

	stable_sort(v.begin(), v.end(), Compare);

	for_each(v.begin(), v.end(), [](pi_s& p) { cout << p.first << " " << p.second << endl; });

	return 0;
}