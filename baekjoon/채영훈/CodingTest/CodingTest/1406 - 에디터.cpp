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
	cin >> text;

	text.insert(text.begin(), ' ');

	int M;
	cin >> M;

	auto cursor = text.end();

	char command = '\0';
	for (size_t i = 0; i < M; i++)
	{
		cin >> command;
		switch (command)
		{
		case 'L':
			if (cursor != text.begin())
				--cursor;
			break;
		case 'D':
			if (cursor != text.end())
				++cursor;
			break;
		case 'B':
			if (cursor != text.begin())
				text.erase(--cursor);
			break;
		case 'P':
			cin >> command;
			text.insert(cursor, command);
			++cursor;
			break;
		}
	}

	cout << text << endl;

	return 0;
}