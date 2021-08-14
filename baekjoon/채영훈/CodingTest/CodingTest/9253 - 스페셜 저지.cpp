#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

using ll = long long;
using ul = unsigned long;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> Pi(const string& part)
{
	int m = part.size(), j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++)
	{
		while (j > 0 && part[i] != part[j])
			j = pi[j - 1];
		if (part[i] == part[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<string> KMP(const string& full, const string& part, const string& result)
{
	vector<string> results;

	auto pi = Pi(part);

	int f_size = full.size(), p_size = part.size(), f_i = 0, p_i = 0;

	while (f_i < f_size && p_i < p_size)
	{
		if (full[f_i] == part[p_i])
			++f_i, ++p_i;
		else if (p_i == 0)
			++f_i;
		else
			p_i = pi[p_i];
	}

	return results;
}

int main()
{
	async_with_stdio;

	string full, part, result;

	cin >> full >> part >> result;

	KMP(full, part, result);
}