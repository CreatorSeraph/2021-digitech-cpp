#include <iostream>
#include <queue>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int N;
	cin >> N;

	queue<int> q;
	string command;

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
				q.push(val);
			}
			else
			{
				if (q.empty()) cout << -1 << nl;
				else
				{
					cout << q.front() << nl;
					q.pop();
				}
			}
			break;
		case 's':
			cout << q.size() << nl;
			break;
		case 'e':
			cout << q.empty() << nl;
			break;
		case 'f':
			if (q.empty()) cout << -1 << nl;
			else cout << q.front() << nl;
			break;
		case 'b':
			if (q.empty()) cout << -1 << nl;
			else cout << q.back() << nl;
			break;
		}
	}

	return 0;
}