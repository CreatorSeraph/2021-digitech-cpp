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

#define SetOf(n) ((ul)1<<(n))
#define Check(s, n) (s & SetOf(n))
#define Add(s, n) (s |= SetOf(n))
#define Remove(s, n) (s &= ~SetOf(n))

int main()
{
	async_with_stdio;

	int M;
	cin >> M;

	ul s = 0;

	string command;
	int val;
	for (size_t i = 0; i < M; i++)
	{
		cin >> command;
		switch (command[0])
		{
		case 'a':
			switch (command[1])
			{
			case 'd':
				cin >> val;
				Add(s, val);
				break;
			case 'l':
				for (size_t i = 0; i < 20; i++)
					Add(s, i + 1);
				break;
			}
			break;
		case 'r':
			cin >> val;
			Remove(s, val);
			break;
		case 'c':
			cin >> val;
			if (Check(s, val))
				cout << "1\n";
			else
				cout << "0\n";
			break;
		case 't':
			cin >> val;
			if (Check(s, val))
				Remove(s, val);
			else
				Add(s, val);
			break;
		case 'e':
			s = 0;
			break;
		}
	}

	return 0;
}