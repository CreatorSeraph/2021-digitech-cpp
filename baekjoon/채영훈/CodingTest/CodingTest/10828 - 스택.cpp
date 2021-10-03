#include <iostream>
#include <stack>

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
	stack<int> s;

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
				s.push(val);
			}
			else
			{
				if (s.empty()) cout << -1 << nl;
				else
				{
					cout << s.top() << nl;
					s.pop();
				}
			}
			break;
		case 's':
			cout << s.size() << nl;
			break;
		case 'e':
			cout << s.empty() << nl;
			break;
		case 't':
			if (s.empty()) cout << -1 << nl;
			else cout << s.top() << nl;
			break;
		}
	}

	return 0;
}