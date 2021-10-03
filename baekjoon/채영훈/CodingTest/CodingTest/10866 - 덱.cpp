#include <iostream>
#include <string>
#include <deque>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int N;
	cin >> N;

	string command;
	deque<int> de;

	for (size_t i = 0; i < N; i++)
	{
		cin >> command;

		switch (command[0])
		{
		case 'p':
			if (command[1] == 'u')
			{
				int val;
				cin >> val;
				if (command[5] == 'f')
				{
					de.push_front(val);
				}
				else
				{
					de.push_back(val);
				}
			}
			else
			{
				if (de.empty()) cout << -1 << nl;
				else
				{
					if (command[4] == 'f')
					{
						cout << de.front() << nl;
						de.pop_front();
					}
					else
					{
						cout << de.back() << nl;
						de.pop_back();
					}
				}
			}
			break;
		case 's':
			cout << de.size() << nl;
			break;
		case 'e':
			cout << de.empty() << nl;
			break;
		case 'f':
			if (de.empty()) cout << -1 << nl;
			else cout << de.front() << nl;
			break;
		case 'b':
			if (de.empty()) cout << -1 << nl;
			else cout << de.back() << nl;
			break;
		}
	}

	return 0;
}