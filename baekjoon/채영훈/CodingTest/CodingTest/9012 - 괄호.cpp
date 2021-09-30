#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main()
{
	async_with_stdio;

	int T; cin >> T;

	string in;

	for (size_t i = 0; i < T; i++)
	{
		cin >> in;

		stack<int> s;

		for (auto&& iter : in)
		{
			switch (iter)
			{
			case '(':
				s.push(1);
				break;
			case ')':
				if (s.empty()) s.push(10);
				else if (s.top() == 1) s.pop();
				break;
			}
		}

		if (s.empty()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}