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
using pi_s = pair<int, string>;
using pi_i = pair<int, int>;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> Nums(int num)
{
	vector<int> nums;

	while (num != 0)
	{
		nums.emplace_back(num % 10);
		num /= 10;
	}

	return nums;
}

vector<char> Nums(string val)
{
	vector<char> vals(val.size() + 1);

	int index = 0;
	for (int i = val.size() - 1; i >= 0; i--)
		vals[index] = val[i], ++index;

	return vals;
}

/// <summary>
/// num에서 target이 있는지 확인하는 함수
/// </summary>
/// <param name="num"></param>
/// <param name="target"></param>
/// <returns></returns>
bool Nums(int num, int target)
{
	while (num != 0)
	{
		if (target == num % 10) return true;
		num /= 10;
	}
	return false;
}

/// <summary>
/// target이 count만큼 num에서 연속적으로 반복되는지 확인하는 함수
/// </summary>
/// <param name="num"></param>
/// <param name="target"></param>
/// <param name="count"></param>
/// <returns></returns>
bool Nums(int num, int target, int count)
{
	int combo = 0;
	while (num != 0)
	{
		if (target == num % 10)
			++combo;
		else
			combo = 0;
		if (combo == count)
			return true;
		num /= 10;
	}
	return false;
}