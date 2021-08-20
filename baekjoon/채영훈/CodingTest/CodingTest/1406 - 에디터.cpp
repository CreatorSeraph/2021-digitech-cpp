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

int main()
{
	async_with_stdio;

	string text;
	list<char> lc;
	cin >> text;

	for_each(text.begin(), text.end(), [&lc](auto& val) {lc.emplace_back(val); });

	int M;
	cin >> M;

	auto cursor = lc.end();

	char command = ' ';
	for (int i = 0; i < M; i++)
	{
		cin >> command;
		switch (command)
		{
		case 'L':
			if (cursor != lc.begin())
				--cursor;
			break;
		case 'D':
			if (cursor != lc.end())
				++cursor;
			break;
		case 'B':
			if (cursor != lc.begin())
				cursor = lc.erase(--cursor);
			break;
		case 'P':
			cin >> command;
			lc.insert(cursor, command);
			break;
		}
	}

	for_each(lc.begin(), lc.end(), [](auto& val) { cout << val; });

	return 0;
}