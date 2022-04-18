#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	char c;
	bool no = false;

	stack<char> c_s;

	string s = "";
	do
	{

		getline(cin, s);

		for (int i = 0; i < s.size(); i++)
		{
			c = s[i];

			if (c == '.')
			{
				if (s[0] == '.') return 0;

				if (!no)
				{
					if (c_s.empty()) cout << "yes" << '\n';
					else cout << "no" << '\n';
				}
				else cout << "no" << '\n';

				s = "";

				for (int i = 0; i < c_s.size(); i++)
				{
					c_s.pop();
				}

				no = false;

				break;
			}

			if (c == '(')
				c_s.push(c);
			else if (c == ')' && !c_s.empty())
			{
				if (c_s.top() == '(')
					c_s.pop();
				else no = true;
			}
			else if (c == ')' && c_s.empty()) no = true;

			if (c == '[')
				c_s.push(c);
			else if (c == ']' && !c_s.empty())
			{
				if (c_s.top() == '[')
					c_s.pop();
				else no = true;
			}
			else if (c == ']' && c_s.empty()) no = true;
		}
	} while (true);

	return 0;
}