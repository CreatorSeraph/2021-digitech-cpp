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
using mc_pc_c = map<char, pc_c>;
using pc_c = pair<char, char>;
using pi_s = pair<int, string>;
using pi_i = pair<int, int>;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

bool Compare(const pi_i& a, const pi_i& b)
{
	return (a.first != b.first ? a.first < b.first : a.second < b.second);
}

int main()
{
	int N;
	cin >> N;

	vector<pi_i> v;
	v.reserve(N);

	int x, y;
	for (size_t i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}

	stable_sort(v.begin(), v.end(), Compare);

	for_each(v.begin(), v.end(), [](pi_i& p) { cout << p.first << " " << p.second << endl; });

	return 0;
}