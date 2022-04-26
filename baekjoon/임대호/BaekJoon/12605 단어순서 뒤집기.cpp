#include <iostream>
#include <stack>
#include <string>

using namespace std;
int 단어순서뒤집기()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	stack<string> s_s;
	string s;
	string s2;
	string r = "";

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		s2 = s;
		getline(cin, s2);
		s += s2;

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == ' ')
			{
				s_s.push(r);
				r = "";
				continue;
			}

			r += s[j];
		}
		s_s.push(r);
		r = "";

		cout << "Case #" << i + 1 << ": ";

		int size = s_s.size();
		for (int j = 0; j < size; j++)
		{
			cout << s_s.top() << ' ';
			s_s.pop();
		}

		if (i < n - 1)
			cout << '\n';
	}

	return 0;
}