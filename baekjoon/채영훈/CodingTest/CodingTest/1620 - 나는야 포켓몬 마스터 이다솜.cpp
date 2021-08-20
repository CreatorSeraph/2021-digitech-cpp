#pragma once
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
using mi_s = map<int, string>;
using ms_i = map<string, int>;
using vpi_s = vector<pair<int, string>>;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main()
{
	async_with_stdio;

	int N, M;

	cin >> N >> M;

	mi_s mi_s;
	ms_i ms_i;

	string name;
	for (size_t i = 1; i <= N; i++)
	{
		cin >> name;
		mi_s.insert({ i,name });
		ms_i.insert({ name,i });
	}

	int val;
	for (size_t i = 0; i < M; i++)
	{
		cin >> name;

		val = atoi(name.c_str());

		if (val != 0) cout << mi_s[val] << "\n";
		else cout << ms_i[name] << "\n";
	}

	return 0;
}