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

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main()
{
	async_with_stdio;

	int N;
	cin >> N;

	set<pair<int, string>> s;

	int age;
	string name;

	for (size_t i = 0; i < N; i++)
	{
		cin >> age >> name;
		s.insert({ age,name });
	}

	for_each(s.begin(), s.end(), [](pair<int, string> p) { cout << p.first << " " << p.second << endl; });

	return 0;
}