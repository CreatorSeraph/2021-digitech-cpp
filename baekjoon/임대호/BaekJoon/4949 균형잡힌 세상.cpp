#include <iostream>
#include <string>
#include <stack>

using namespace std;

int ±ÕÇüÀâÈù¼¼»ó()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	char c;
	bool no = false;

	string s = "";
	do
	{
		getline(cin, s);

		if (s == ".") break;

		no = false;
		stack<char> c_s;

		for (int i = 0; i < s.size(); i++)
		{
			c = s[i];

			if (c == '(' || c == '[')
				c_s.push(c);

			else if (c == ')')
			{
				if (!c_s.empty() && c_s.top() == '(')
					c_s.pop();
				else
				{
					no = true;
					break;
				}
			}

			else if (c == ']')
			{
				if (!c_s.empty() && c_s.top() == '[')
					c_s.pop();
				else
				{
					no = true;
					break;
				}
			}
		}

		if (!no)
		{
			if (c_s.empty()) cout << "yes" << '\n';
			else cout << "no" << '\n';
		}
		else cout << "no" << '\n';

	} while (true);

	return 0;
}